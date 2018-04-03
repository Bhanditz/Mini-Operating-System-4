#include "../include/shell.h"
/* New shell is launched as soon as we make file or try to get recursive shall */
void launch_shell(int n)
{
	// Assign memory to scan the input
	string ch = (string) malloc(200); // util.h
	int counter = 0;
	do
	{
			print("miniOS (");
			print(int_to_string(n));
			print(")> ");
		    // Scan the input
		    ch = readStr(); //memory_copy(readStr(), ch,100);
		    // New Console
		    if(strEql(ch,"cmd"))
		    {
		            print("\nYou are already in cmd. A new recursive shell is opened\n");
					launch_shell(n+1);
		    }// Clear screen
		    else if(strEql(ch,"clear"))
		    {
		            clearScreen();
		    }// Exit the present console
		    else if(strEql(ch,"exit"))
		    {
		    	print("\nGood Bye!\n");
		    }// Reprint the input
		    else if(strEql(ch,"echo"))
		    {
		    	echo();
		    }// Sort given numbers
		    else if(strEql(ch,"sort"))
		    {
		    	sort();
		    }// List the functionalities available in miniOS
		    else if(strEql(ch,"help"))
		    {
		    	help();
		    }// Change the text and background colour
		    else if(strEql(ch,"color"))
		    {
		    	set_background_color();
		    }// Use few features of Calculator
		    else if(strEql(ch,"calc"))
		    {
		    	calc();
		    }// If string doesn`t match any of the available function
		    else
		    {
		            print("\nBad command!\n");
			    print("Type help command to list all the commands."); 
		    } 
	} while (!strEql(ch,"exit"));
}

/* Implementation of Calculator */
void calc()
{
	while(1){
		print("\n press 1 for addition");
		print("\n press 2 for subtraction");
		print("\n press 3 for multiplication");
		print("\n press 4 for division");
		print("\n press 5 for percentage");
		print("\n press 0 for exit");
		print("\n");
		int x = str_to_int(readStr());
		if(x==0){
			print("\n");
			break;
		}		
		if(x==1)
		{
			print("\nEnter 1st number : ");		
			int a =	str_to_int(readStr());
			print("\nEnter 2nd number : ");
			int b = str_to_int(readStr());
			print("\nans : ");
			print(int_to_string(a+b));
		}
		if(x==2)
		{
			print("\nEnter 1st number : ");		
			int a =	str_to_int(readStr());
			print("\nEnter 2nd number : ");
			int b = str_to_int(readStr());
			print("\nans : ");
			print(int_to_string(a-b));
		}
		if(x==3)
		{
			print("\nEnter 1st number : ");		
			int a =	str_to_int(readStr());
			print("\nEnter 2nd number : ");
			int b = str_to_int(readStr());
			print("\nans : ");
			print(int_to_string(a*b));
		}
		if(x==4)
		{
			print("\nEnter Dividend : ");		
			int a = str_to_int(readStr());
			print("\nEnter Divisor : ");
			int b = str_to_int(readStr());
			print("\nans : ");
			print(int_to_string(a/b));
		}
		if(x==5)
		{
			print("\nenter 1st number : ");		
			int a =	str_to_int(readStr());
			print("\nenter 2nd number : ");
			int b = str_to_int(readStr());
			print("\nans : ");
			print(int_to_string(a*b/100));
		}
	}
}

/* Implementation of Echo function */
void echo()
{
	print("\n");
	string str = readStr();
	print("\n");
	print(str);
	print("\n");
}

/* Implementation of Sort function */
void sort()
{ 
	int arr[100];
	print("\nArray size: ");
	int n = str_to_int(readStr());
	print("\n");
	fill_array(arr,n);
	print("Before Sorting:\n");
	print_array(arr,n);
	print("\nOrder: (1 for increasing/ 0 for decreasing): ");
	int ordre = str_to_int(readStr());
	insertion_sort(arr,n,ordre);
	print("\nAfter Sorting:\n");
	print_array(arr,n);
}

/* Implementation of Scanning each element of array in sort function */
void fill_array(int arr[],int n)
{
	int i = 0;
	for (i = 0;i<n;i++)
	{
		print("ARR[");
		print(int_to_string(i));
		print("]: ");
		arr[i] = str_to_int(readStr());
		print("\n");
	}
}

/* Implementation of Printing the array required in sort function */
void print_array(int arr[],int n)
{
	int i = 0;
	for (i = 0;i<n;i++)
	{
		print("ARR[");
		print(int_to_string(i));
		print("]: ");
		print(int_to_string(arr[i]));
		print("   ");
	}
	print("\n");
}

/* Sorting the array required in sort function 
 * Order = 1 for increasing, Order = 0 for descreasing
 */
void insertion_sort(int arr[],int n,int order)
{       /* Increasing */
	if(order){
		int i = 0;
		for (i = 1;i<n;i++)
		{
			int aux = arr[i];
			int j = i;
			while((j > 0) && ((aux < arr[j-1])))
			{
				arr[j] = arr[j-1];
				j = j -1;
			}
			arr[j] = aux;
		}
	}/* Decreasing */
 	else{
		int i = 0;
		for (i = 1;i<n;i++)
		{
			int aux = arr[i];
			int j = i;
			while((j > 0) && ((aux > arr[j-1])))
			{
				arr[j] = arr[j-1];
				j = j -1;
			}
			arr[j] = aux;
		}
	
	}
}

/* Change Background Colour */
void set_background_color()
{
	print("\nColor codes : ");
	print("\n0 : black");
	print_colored("\n1 : blue",1,0);   // screen.h
	print_colored("\n2 : green",2,0);
	print_colored("\n3 : cyan",3,0);
	print_colored("\n4 : red",4,0);
	print_colored("\n5 : purple",5,0);
	print_colored("\n6 : orange",6,0);
	print_colored("\n7 : grey",7,0);
	print_colored("\n8 : dark grey",8,0);
	print_colored("\n9 : blue light",9,0);
	print_colored("\n10 : green light",10,0);
	print_colored("\n11 : blue lighter",11,0);
	print_colored("\n12 : red light",12,0);
	print_colored("\n13 : rose",13,0);
	print_colored("\n14 : yellow",14,0);
	print_colored("\n15 : white",15,0);
	
	print("\n\n Text color ? : ");
	int text_color = str_to_int(readStr());
	print("\n\n Background color ? : ");
	int bg_color = str_to_int(readStr());
	set_screen_color(text_color,bg_color);
	clearScreen();
}

/* Print all the functions available and their usage */
void help()
{
	print("\ncmd       : Launch a new recursive Shell");
	print("\nclear     : Clears the screen");
	print("\necho      : Reprint a given text");
	print("\nsort      : Sorts a given n numbers");
	print("\nexit      : Quits the current shell");
	print("\ncolor     : Changes the colors of the terminal");
	print("\ncalc      : Basic calucator to add, subtract, multiply or divide 2 numbers");
	print("\n\n");
}

