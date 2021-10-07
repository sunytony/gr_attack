#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir="/home/seungmin/git/gr_attack/gr-attack/python"
export GR_CONF_CONTROLPORT_ON=False
export PATH="/home/seungmin/git/gr_attack/gr-attack/build/python":$PATH
export LD_LIBRARY_PATH="":$LD_LIBRARY_PATH
export PYTHONPATH=/home/seungmin/git/gr_attack/gr-attack/build/swig:$PYTHONPATH
/usr/bin/python3 /home/seungmin/git/gr_attack/gr-attack/python/qa_modified_RAPP.py 
