for ((i=0;i<=97;i++))
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
echo
echo -n "Enter your choice: "

read n1

case $n1 in
	1)
			gcc fcfs.c
			./a.out
			;;
			
	2)	
			echo "1.Pre-emptive"
			echo "2.Non Pre-emptive"
			echo "Enter your choice: "
			read n2
			case $n2 in
				1)
		 			 gcc sjf_pre.c
		 			 ./a.out
					 ;;
				2)
		 			 gcc sjf_non.c
		 			 ./a.out
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
		 			 gcc pr_pre.c
		 			 ./a.out
					 ;;
				2)
		 			 gcc pr_non.c
		 			 ./a.out
					 ;;
			esac
			;;
			
	4)
			gcc robin.c
		 	./a.out
			;;
	
esac
		
bash repeat.sh
						




