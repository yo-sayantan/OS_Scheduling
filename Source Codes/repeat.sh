echo
echo -n "Do you want to continue (1/0)?: "
read ch

if [ $ch -eq 1 ]
then 
	bash link.sh
elif [ $ch -eq 0 ]
then
	echo
	echo "Thank You"
	echo
	for ((i=0;i<=40;i++))
	do
		echo -n "-x"	
	done
	echo 
	echo
else
	echo "Invalid Choice..!!"
fi
 

