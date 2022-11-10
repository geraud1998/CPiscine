ifconfig -a link | grep 'ether' | awk '{print $2}' | tr -d '	' | tr -d ' '
