#!/bin/bash

###################################################
#                                                 #
# This Bash script install required dependencies  #
# for using this sandbox. Requires sudo           #
#                                                 #
###################################################

# Some colors for the logs
RED="\033[0;31m";
BLUE="\033[0;34m";
GREEN="\033[0;32m";
NOCOLOR="\033[0m";

# Check if running with sudo
if [[ $EUID -ne 0 ]]; then
  printf "\n[%s] [${RED}ERROR${NOCOLOR}] sudo required\n\n" "$(date +"%T")";
  exit 1;
fi

# Update deps
printf "\n[%s] [${BLUE}INFO${NOCOLOR}] Updating deps\n" "$(date +"%T")";
sudo apt update;

# Install deps
printf "\n[%s] [${BLUE}INFO${NOCOLOR}] Installing deps\n" "$(date +"%T")";
sudo apt install build-essential gcc gpp make cmake;

# Check g++ install
printf "\n[%s] [${BLUE}INFO${NOCOLOR}] Checking g++ version\n" "$(date +"%T")";
g++ -v;

# Clone GoogleTest
if [[ ! -e './googletest' ]]; then
  printf "\n[%s] [${BLUE}INFO${NOCOLOR}] Cloning GoogleTest\n" "$(date +"%T")";
  git clone git@github.com:google/googletest.git;
else
  printf "\n[%s] [${BLUE}INFO${NOCOLOR}] 'googletest' directory found. Skipping GoogleTest clone\n" "$(date +"%T")";
fi

# Done
printf "\n[%s] [${GREEN}INFO${NOCOLOR}] Checking version\n" "$(date +"%T")";

# EOF