#!/bin/sh

###############
## VARIABLES ##
###############

# Colors
blue='\033[0;34m'
cyan='\033[0;36m'
green='\033[1;32m'
red='\033[0;31m'
nocol='\033[0m'


############### END VARIABLES ##############

###############
## FUNCTIONS ##
###############

install_dirs() {
	cd /usr/bin/ && sudo mkdir -p c_utils/user_dir/
}


############## END FUNCTIONS ##############


## MAIN SCRIPT ##

# Check if install dir is present already
if [ ! -e /usr/bin/c_utils/user_dir ]; then
	echo "[*] Creating Directories..."
	install_dirs
else
	echo "[*] Directories already exist."
fi

echo "[*] Compiling$blue whosyodaddy $nocol \n\n"
make whosyodaddy
echo -e "\n\nDo You want to install? (0/1): "
read inst_ch
if [ $inst_ch -eq 0 ]; then
	echo ":: All binaries have been compiled. run $red'make install'$nocol to install them.\n"
	exit
else if [ $inst_ch -eq 1 ]; then
	make install
 else
	echo "$red BAD CHOICE $nocol"
	echo ":: All binaries have been compiled. run $red'make install'$nocol to install them."
	exit
fi
fi
echo "\n$green[*] All binaries have been compiled and installed.$nocol\n"