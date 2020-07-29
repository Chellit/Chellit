 #!/usr/bin/env bash

 # Execute this file to install the chellit cli tools into your path on OS X

 CURRENT_LOC="$( cd "$(dirname "$0")" ; pwd -P )"
 LOCATION=${CURRENT_LOC%Chellit-Qt.app*}

 # Ensure that the directory to symlink to exists
 sudo mkdir -p /usr/local/bin

 # Create symlinks to the cli tools
 sudo ln -s ${LOCATION}/Chellit-Qt.app/Contents/MacOS/chellitd /usr/local/bin/chellitd
 sudo ln -s ${LOCATION}/Chellit-Qt.app/Contents/MacOS/chellit-cli /usr/local/bin/chellit-cli
