#ifndef SHARED_INTERACTIVE_CURVE_VIEW_RANGE_H
#define SHARED_INTERACTIVE_CURVE_VIEW_RANGE_H

#include <stdint.h>
#include "memoized_curve_view_range.h"
#include "interactive_curve_view_range_delegate.h"
#include <ion/display.h>
#include <float.h>

namespace Shared {

class InteractiveCurveViewRange : public MemoizedCurveViewRange {
public:
  InteractiveCurveViewRange(InteractiveCurveViewRangeDelegate * delegate = nullptr) :
    MemoizedCurveViewRange(),
    m_delegate(nullptr),
    m_offscreenYAxis(0.f),
    m_zoomAuto(true),
    m_zoomNormalize(false)
  {
    if (delegate) {
      setDelegate(delegate);
    }
  }

  static constexpr float NormalYXRatio() { return NormalizedYHalfRange(1.f) / NormalizedXHalfRange(1.f); }
  /* The method isOrthonormal takes the loss of significance when changing the
   * ratio into account. */
  bool isOrthonormal() const;

  void setDelegate(InteractiveCurveViewRangeDelegate * delegate);

  bool zoomAuto() const { return m_zoomAuto; }
  void setZoomAuto(bool v);
  bool zoomNormalize() const { return m_zoomNormalize; }
  void setZoomNormalize(bool v);
  float roundLimit(float y, float range, bool isMin);

  // MemoizedCurveViewRange
  float xGridUnit() const override { return m_zoomNormalize ? yGridUnit() : MemoizedCurveViewRange::xGridUnit(); }
  float yGridUnit() const override;

  // CurveViewWindow
  void setXMin(float f) override;
  void setXMax(float f) override;
  void setYMin(float f) override;
  void setYMax(float f) override;

  void setOffscreenYAxis(float f) { m_offscreenYAxis = f; }

  // Window
  void zoom(float ratio, float x, float y);
  void panWithVector(float x, float y);
  virtual void normalize(bool forceChangeY = false);
  virtual void setDefault();
  void centerAxisAround(Axis axis, float position);
  void panToMakePointVisible(float x, float y, float topMarginRatio, float rightMarginRatio, float bottomMarginRation, float leftMarginRation, float pixelWidth);

protected:
  constexpr static float k_upperMaxFloat = 1E+8f;
  constexpr static float k_lowerMaxFloat = 9E+7f;
  constexpr static float k_maxRatioPositionRange = 1E5f;
  /* The tolerance is chosen to normalize sqrt(x) */
  constexpr static float k_orthonormalTolerance = 1.78f;
  static float clipped(float x, bool isMax) { return Range1D::clipped(x, isMax, k_lowerMaxFloat, k_upperMaxFloat); }
  /* In normalized settings, we put each axis so that 1cm = 2 units. For now,
   * the screen has size 43.2mm * 57.6mm.
   * We want:
   *   2 * normalizedXHalfRange -> 57.6mm
   *   2 * 1 unit -> 10.0mm
   * So normalizedXHalfRange = 57.6mm * 1 unit / 10.0mm */
  constexpr static float NormalizedXHalfRange(float unit) { return 5.76f * unit; }
  /* In normalized settings, we put each axis so that 1cm = 2 units. For now,
   * the screen has size 43.2mm * 57.6mm.
   * We want:
   *   2 * normalizedYHalfRange -> 43.2mm * 170/240
   *   2 * 1 unit -> 10.0mm
   * So normalizedYHalfRange = 43.2mm * 170/240 * 1 unit / 10.0mm */
  constexpr static float NormalizedYHalfRange(float unit) {  return 3.06f * unit; }
  bool shouldBeNormalized() const;
  virtual bool hasDefaultRange() const { return (xMin() == std::round(xMin())) && (xMax() == std::round(xMax())); }

  InteractiveCurveViewRangeDelegate * m_delegate;
private:
  float offscreenYAxis() const override { return m_offscreenYAxis; }
  int normalizationSignificantBits() const;

  float m_offscreenYAxis;
  bool m_zoomAuto;
  bool m_zoomNormalize;
};

static_assert(Ion::Display::WidthInTenthOfMillimeter == 576, "Use the new screen width to compute Shared::InteractiveCurveViewRange::NormalizedXHalfRange");
static_assert(Ion::Display::HeightInTenthOfMillimeter == 432, "Use the new screen height to compute Shared::InteractiveCurveViewRange::NormalizedYHalfRange");

typedef void (InteractiveCurveViewRange::*ParameterSetterPointer)(float);
typedef float (InteractiveCurveViewRange::*ParameterGetterPointer)() const;
typedef void (InteractiveCurveViewRange::*RangeMethodPointer)();

}

#endif
