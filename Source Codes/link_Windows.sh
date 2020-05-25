for ((i=0;i<=80;i++))
	do
		echo -n "-"	
	done

echo
echo
echo "The available choices are -"
echo "1.First Come First Serve Scheduling"
echo "2.Shortest Job First Scheduling"
echo "3.Priority Scheduling"
echo "4.Round Robin Scheduling"
echo "5.Exit"
echo
echo -n "Enter your choice: "

read n1

case $n1 in
	1)
			wine fcfs.exe
			./a.out
			;;
			
	2)	
			echo "1.Pre-emptive"
			echo "2.Non Pre-emptive"
			echo "Enter your choice: "
			read n2
			case $n2 in
				1)
		 			 wine sjf_pre.exe
					 ;;
				2)
		 			 wine sjf_non.exe
					 ;;
			esac
			;;
			
	3)
			echo "1.Pre-emptive"
			echo "2.Non Pre-emptive"
			echo "Enter your choice: "
			read n3
			case $n3 in
				1)
		 			 wine pr_pre.exe
					 ;;
				2)
		 			 wine pr_non.exe
					 ;;
			esac
			;;
			
	4)
			start ./robin.exe
			;;
			
	5)
			echo
			echo "Thank You"
			echo
			for ((i=0;i<=40;i++))
			do
				echo -n "-x"	
			done
			echo 
			echo
	
esac
		
bash repeat.sh
						




