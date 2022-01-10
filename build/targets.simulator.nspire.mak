$(BUILD_DIR)/%.tns: $(BUILD_DIR)/%.elf
	$(GENZEHN) --input $^ --output $@.zehn $(ZEHNFLAGS)
	make-prg $@.zehn $@
	rm $@.zehn
