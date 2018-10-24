ex2_input.txt
while ln ex2_input.txt ex2_input.txt.lock 2>/dev/null
do
	sleep 1
done
a=0
while [ $a -lt 10 ]
do
	num=$(tail -n 1 ex2_input.txt)
	echo $(($num + 1)) >> ex2_input.txt
	a=$((a+1))
done
rm -f ex2_input.txt.lock

	
