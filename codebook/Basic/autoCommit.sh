# !/bin/bash

while :
do
	git push > /dev/null 2>&1
	for i in {1..20}
	do
		git add --all
		git commit -m "autocommit" > /dev/null
		sleep 5
	done
done
