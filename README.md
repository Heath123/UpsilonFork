<p align="center"><img src="https://github.com/Laporte12974/UpsilonDesign/blob/89a15953ae128aef8aa7d066dcaaf8d5c70f02a5/UPSILogo.png" /></p>

<p align="center">
  <a href="https://creativecommons.org/licenses/by-nc-sa/4.0/"><img alt="cc by-nc-sa 4.0" src="https://img.shields.io/badge/License-CC%20BY--NC--SA%204.0-525252.svg?labelColor=292929&logo=creative%20commons&style=for-the-badge" /></a>
  <a href="https://github.com/Lauryy06/Upsilon/issues"><img alt="Issues" src="https://img.shields.io/github/issues/Lauryy06/Upsilon.svg?labelColor=292929&logo=git&style=for-the-badge" /></a>
  <br/>
  <a href="https://discord.gg/hnEqPzAJzn"><img alt="Discord" src="https://img.shields.io/discord/663420259851567114?color=blue&labelColor=292929&label=chat%20-%20discord&logo=discord&style=for-the-badge" /></a>
</p>

> Vous ne comprenez pas l'anglais ? Vous êtes francophone ? Regardez le [*LISEZ-MOI* français](./README.fr.md) !

## About

Upsilon is a fork of Omega, an user-made OS that runs on the Numworks calculator, which brings many features to it, but was discontinued because of a policy change from Numworks. Upsilon is for the people who want to see a future for user-made OSes for Numworks, even after the closure and archiving of Omega.




### Some new features
- Enhancements for the Kandinsky python module
- Support for wallpapers
- External apps
- A custom theme
- Operator overload for python
- Improvements for the Periodic table application
- *And everything that has been added to Omega before its termination!* [See Omega's changelog here](https://github.com/Omega-Numworks/Omega/wiki/Changelog) | [Main Omega features + screenshots](https://github.com/Omega-Numworks/Omega/wiki/Main-features).

<br>

## Installation

### Installer

Go to the [Upsilon website](https://lolocomotive.github.io/Upsilon-website) to the "Install" section. 
If your calculator is recognized, contains a version of Epsilon lower than 16 and your browser accepts WebUSB, the page will suggest you to install Upsilon.
Do not disconnect your calculator until the installation is complete.

### Manual

 *You can refer to this [website](https://www.numworks.com/resources/engineering/software/build/) for the first step if you get errors.*



### 1. Install SDK

<br>

<details>
<summary><b>1.1 Linux</b></summary>

<br>


<details>
<summary>Debian or Ubuntu</summary>

<br>

You just have to install dependencies by running these command with superuser privileges in a Terminal:

```bash
apt-get install build-essential git imagemagick libx11-dev libxext-dev libfreetype6-dev libpng-dev libjpeg-dev pkg-config gcc-arm-none-eabi binutils-arm-none-eabi
```

And there you can go to step 2!

<br>

</details>

<details>
<summary>Fedora</summary>

<br>

First install basics dev tools.

```bash
dnf install make automake gcc gcc-c++ kernel-devel
```

Then install required packages.

```bash
dnf install git ImageMagick libX11-devel libXext-devel freetype-devel libpng-devel libjpeg-devel pkg-config
```

Then, install GCC cross compiler for ARM.

```bash
dnf install arm-none-eabi-gcc-cs arm-none-eabi-gcc-cs-c++
```

<br>

</details>

<br>

</details>

<details>
<summary><b>1.2 Mac</b></summary>

<br>

It's recommended to use [Homebrew](https://brew.sh/). Once it's installed, just run:
```bash
brew install numworks/tap/epsilon-sdk
```
and it will install all dependencies.

<br>

And there you can go to step 2!

<br>



</details>

<details>
<summary><b>1.3 Windows</b></summary>

<br>
<details>
<summary>With Msys2/Mingw (officialized by numworks but with a lot of bugs)</summary>
[Msys2](https://www.msys2.org/) environment is recommended by Numworks to get most of the required tools on Windows easily. It's where you'll paste all the commands of this tutorial. Once it's installed, paste these commands into the Msys2 terminal.

```bash
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-freetype mingw-w64-x86_64-pkg-config mingw-w64-x86_64-libusb git make python
echo "export PATH=/mingw64/bin:$PATH" >> .bashrc
```

Next, you'll need to install the [GCC toolchain for ARM](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads). When prompted for an install location, choose `C:\msys64\home\User\gcc-arm\`. You'll then need to add this folder to your $PATH. Just enter:

```bash
echo "export PATH=$PATH:$HOME/gcc-arm/bin" >> .bashrc
```
Just restart terminal and you can go to step 2!

</details>

<details>
<summary>With WSL 2</summary>


You need a windows version >= 1903.

#### WSL Installation

1. Use simultaneously win + X keys and then click on "admin powershell".
```powershell
dism.exe /online /enable-feature /featurename:Microsoft-Windows-Subsystem-Linux all /norestart
```
This command activate WSL functionalities.

```powershell
dism.exe /online /enable-feature /featurename:VirtualMachinePlatform /all /norestart
```
This one allows virtual machines developed by Microsoft.

2. Restart your computer.

3. Download [this file](https://wslstorestorage.blob.core.windows.net/wslblob/wsl_update_x64.msi) and follow instructions.

4. Now open powershell admin like before and type:
```powershell
wsl --set-default-version 2
```
5. Download [Ubuntu](https://www.microsoft.com/store/apps/9n6svws3rx71) from Microsoft store.

WSL is now installed.

### Usbipd installation to connect your calculator
If you want to connect to the calculator, you have to connect to install this [tool](https://github.com/dorssel/usbipd-win/releases/download/v1.3.0/usbipd-win_1.3.0.msi). This will allow you to connect WSL to the calculator through internet. Follow the on screen information to install.
#### Ubuntu
1. In a WSL Ubuntu command prompt, type:
```bash
sudo apt install linux-tools-5.4.0-77-generic hwdata
```
2. Edit /etc/sudoers so that root can find the usbip command. On Ubuntu, run this command.
```bash
sudo visudo
```
3. Add `/usr/lib/linux-tools/5.4.0-77-generic` to the beginning of secure_path. After editing, the line should look similar to this.
`Defaults secure_path="/usr/lib/linux-tools/5.4.0-77-generic:/usr/local/sbin:..."`

#### Debian
1. If you use debian for your WSL distro, use this command instead:
```bash
sudo apt install usbip hwdata usbutils
```
And that's all for installation and set up.

### To connect your calculator
1. Open an Admin powershell and type:
```powershell
  usbipd wsl list
```
This will list your usb devices connected. Look at the BUSID column and remember the one for your calculator (it should be called "Numworks Calculator").
2. Now run this command replacing <BUSID> by your calculator's usb port id:
```powershell
usbipd wsl attach --busid <BUSID>
```
It will ask you to type your wsl's password and will connect your calculator to WSL.

You can now go to step 2!
</details>

</details>

<br>

### 2. Set up repo


Clone repo and use 'upsilon-dev' branch by pasting these two commands:

```bash
git clone --recursive https://github.com/Lauryy06/Upsilon.git
cd Upsilon
git checkout upsilon-dev
```
<br>


### 3. Choose the target


<details>
  <summary><b>Model n0100</b></summary>

(note: you can change the `EPSILON_I18N=en` flag to `fr`, `nl`, `pt`, `it`, `de`, `es` or `hu`).

```bash
make MODEL=n0100 clean
make MODEL=n0100 EPSILON_I18N=en OMEGA_USERNAME="{Your name, max 15 characters}" -j4
```

Now, run either:

```bash
make MODEL=n0100 epsilon_flash
```
to directly flash the calculator after pressing simultaneously `reset` and `6` buttons and plugging in.

<br>

or:

```bash
make MODEL=n0100 OMEGA_USERNAME="" binpack -j4
```
to make binpack witch you can flash to the calculator from [Ti-planet's webDFU](https://ti-planet.github.io/webdfu_numworks/n0100/). Binpacks are a great way to share a custom build of Upsilon to friends.
  
</details>

<details>
  <summary><b>Model n0110</b></summary>


```bash
make clean
make OMEGA_USERNAME="{Your name, max 15 characters}" -j4
```

Now, run either:

```bash
make epsilon_flash
```
to directly flash the calculator after pressing simultaneously `reset` and `6` buttons and plugging in.

<br>

or:

```bash
make OMEGA_USERNAME="" binpack -j4
```
to make binpack witch you can flash to the calculator from [Ti-planet's webDFU](https://ti-planet.github.io/webdfu_numworks/n0110/). Binpacks are a great way to share a custom build of Upsilon to friends.

</details>

<details>
  <summary><b>Web simulator</b></summary>
  
First, install emsdk :

```bash
git clone https://github.com/emscripten-core/emsdk.git
cd emsdk
./emsdk install latest-fastcomp
./emsdk activate latest-fastcomp
source emsdk_env.sh
```

Then, compile Upsilon :

```bash
make clean
make PLATFORM=simulator TARGET=web OMEGA_USERNAME="{Your name, max 15 characters}" -j4
```

The simulator is now in `output/release/simulator/web/simulator.zip`


</details>

<details>
  <summary><b>3DS Simulator</b></summary>
  
You need devkitPro and devkitARM installed and in your path (instructions [here](https://devkitpro.org/wiki/Getting_Started))

```bash
git clone --recursive https://github.com/Lauryy06/Upsilon.git
cd Upsilon
git checkout --recursive upsilon-dev
make PLATFORM=simulator TARGET=3ds -j
```
You can then put epsilon.3dsx on a SD card to run it from the HBC or use 3dslink to launch it over the network:

```bash
3dslink output/release/simulator/3ds/epsilon.3dsx -a <3DS' IP ADDRESS>
```

</details>

<details>
  <summary><b>TI-Nspire Simulator</b></summary>

First, build and install [Ndless SDK](https://hackspire.org/index.php/C_and_assembly_development_introduction);

Then compile Upsilon specifying the target:

```bash
make clean
make PLATFORM=simulator TARGET=nspire -j4
```

Copy epsilon.tns to either Nspire Touchpad or CX with [Ndless](https://ndless.me) installed and run it from My Documents.

Please note that the executable is in [Zehn format](https://hackspire.org//index.php?title=Zehn) thus
Ndless 3.1 or a later version is required.

Keyboard mapping method is not perfect and is subject to change.

</details>

<br>

Important: Don't forget the `--recursive` tag, because Upsilon relies on submodules.
Also, you can change the number of processes that run in parallel during the build by changing the value of the `-j` flag.
Don't forget to put your pseudo instead of `{your pseudo, max 15 char}`. If you don't want one, just remove the `OMEGA_USERNAME=""` argument.

<br>

If you need help, you can join our Discord server here : https://discord.gg/NFvzdCBTQn

<a href="https://discord.gg/NFvzdCBTQn"><p align="center"><img alt="Omega Banner Discord" src="https://user-images.githubusercontent.com/12123721/86287349-54ef5800-bbe8-11ea-80c1-34eb1f93eebd.png" /></p></a>
---
## Useful links
* [Upsilon external (to install additional apps and wallpapers)](https://lauryy06.github.io/Upsilon-External/)
* [Ulab documentation](https://micropython-ulab.readthedocs.io/en/latest/)

## Contributing

To contribute, please refer to [Omega's Wiki](https://github.com/Omega-Numworks/Omega/wiki/Contributing), the same rules apply here.
  
## Related repositories

Here are the main links toward Omega's different websites and repositories, that have been used for the creation of Upsilon.

* [Omega Themes](https://github.com/Omega-Numworks/Omega-Themes)
* [Omega Website](https://github.com/Omega-Numworks/Omega-Website)
* [Omega RPN `APP`](https://github.com/Omega-Numworks/Omega-RPN)
* [Omega Atomic `APP`](https://github.com/Omega-Numworks/Omega-Atomic)
* [Omega Design](https://github.com/Omega-Numworks/Omega-Design)
* [Omega Discord Bot](https://github.com/Omega-Numworks/Omega-Discord-Bot)
* [Omega App Template `BETA`](https://github.com/Omega-Numworks/Omega-App-Template)
* [External Apps](https://github.com/Omega-Numworks/External-Apps)

## About Epsilon

Upsilon is a fork of Omega, after the project's discontinuation.

Omega is a fork of Epsilon, a high-performance graphing calculator operating system. It includes eight apps that cover the high school mathematics curriculum.

You can try Epsilon straight from your browser in the [online simulator](https://www.numworks.com/simulator/).

## License

NumWorks is a registered trademark of NumWorks SAS, 24 Rue Godot de Mauroy, 75009 Paris, France.<br>
Nintendo and Nintendo 3DS are registered trademarks of Nintendo of America Inc, 4600 150th Ave NE, Redmond, WA 98052, USA.<br>
NumWorks SAS and Nintendo of America Inc aren't associated in any shape or form with this project.<br>
TI-Nspire is a registered trademark of Texas Instruments, Inc.

* NumWorks Epsilon is released under a [CC BY-NC-SA License](https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode).
* Omega is released under a [CC BY-NC-SA License](https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode).
* Upsilon is released under a [CC BY-NC-SA License](https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode).

