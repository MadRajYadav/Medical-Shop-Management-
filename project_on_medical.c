#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>// to use exit() function and further used in dynamic memory allocation
#include<time.h>
int sn ,leap, l_size, l_prize, jar, j_prize, rack, flag=0,i,sr_flag=0;	// global variable
char medicine[30], ex_date[12],s_medicine[30],current_date[11]; // global variable
long file_point=90;
// declaration of user defined function 
//COMBIFLAM, AVIL, aciloc, nise, paracetamol
void main();
int comp_date(char *ex_date, char *cr_date);
void current_date_();
int validate_date();
void get_data();
void create_file();
void write_data();
void show_data();
void input_medicine();
void search_medicine();
void display_medicine();
void delete_data(int sn1);
void delete_medicine();
void make_bill();
//end

void show_data(){
	if( leap == 0 && l_size == 0)	// to check whether it is jar or tablets (jar)
		printf("S.No : %d \nRack No. : %d  \nMedicine Name : %s \nTotal Jar : %d	\nJar Prize : %d \nExpire Date : %s\n\n",sn ,rack,medicine,jar,j_prize,ex_date);
	else if( leap != 0 && l_size != 0)	// to check whether it is jar or tablets (tablets)
		printf("S.No : %d \nRack No. : %d  \nMedicine Name : %s  \nTablets : %d  \nLeap Size : %d \nLeap Prize : %d \nExpire Date : %s\n\n",sn ,rack,medicine,leap,l_size,l_prize,ex_date);
	else
		printf("\n\t\t\t******__________Unexpected Error__________******\n\n"); //eror
}
void write_data(){
	system("cls"); // to clear output consol
printf("\t\t\t\t$$$$$$__________WELCOME TO MEDICAL SHOP__________$$$$$$\n\t\t\t\t\t     _______by M.Raj Yadav_______\n\n");
	FILE *f;	// file pointer
	char ch=NULL;
	flag=0;
	f = fopen("medical.txt","r+");	// opening of file in read and write mode
	while((ch=fgetc(f))!=EOF)	
		if(ch=='\n')// counting the line 
			flag++;	// to store file has how many line
	fclose(f);	// file closed
	f = fopen("medical.txt","a");	// opening of file in append mode
//	fputs("\nSn.	Rack_no.	medicine_name	tablets_leap	tablets_in_leap	leap_prize	jar	jar_prize	expire_date",f);		
	// writing the data on .txt file
	fprintf(f,"%d\t\t%d\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n",flag,rack,strlwr(medicine),leap*l_size,l_size,l_prize,jar,j_prize,ex_date);
	printf("\t\t\t\t  ######__________Data inserted__________######\n\n");
	fclose(f);	// file closed
	printf("\nPLease enter any key :~~~~~~~~$ ");
	getch();
	system("cls");
	printf("\t\t\t\t$$$$$$__________WELCOME TO MEDICAL SHOP__________$$$$$$\n\t\t\t\t\t     _______by M.Raj Yadav_______\n\n");
	flag=rack=leap=l_size=l_prize=jar=j_prize=0;
	medicine[0]=ex_date[0]='\0';
	
}
void get_data(){
	system("cls");	// clear consol
printf("\t\t\t\t$$$$$$__________WELCOME TO MEDICAL SHOP__________$$$$$$\n\t\t\t\t\t     _______by M.Raj Yadav_______\n\n");
	// initializing of variable
	leap=l_size=l_prize=jar=j_prize=rack=0;
	medicine[0]='\0'; ex_date[0]='\0';
	int tr=1;
	char medicine_type;			
	printf("\n\t\t\t   ******__________Click 'n' if it was wrong choice__________****** \n\nEnter medicine Name :~~~~~~~~$ ");
	fflush(stdin);	// flushing the buffer memory
	gets(medicine);
	if((medicine[0]=='n' ||	medicine[0]=='N') && medicine[1]=='\0' )
		main();
	printf("\nIs it a Tablet (y/n) :~~~~~~~~$ ");
	scanf("%c",&medicine_type);
	if(medicine_type=='y' || medicine_type=='Y'){	// to check the given medicine name is tablets or jar (bottle)
		// code for inputing data which will be tablets
		printf("\nEnter total number of leap of Tablets (Piece) :~~~~~~~~$ ");
		scanf("%d",&leap);
		printf("\nEnter total number of Tablets in a leap :~~~~~~~~$ ");
		scanf("%d",&l_size);
		printf("\nEnter prize of leap of tablets :~~~~~~~~$ ");
		scanf("%d",&l_prize);	
	}
	else {
			// code for inputing data which will be jar or bottle
		printf("\nEnter total number of Jar or Bottle (Piece) :~~~~~~~~$ ");
		scanf("%d",&jar);
		printf("\nEnter prize of jar or Bottle :~~~~~~~~$ ");
		scanf("%d",&j_prize);		
	}
	printf("\nEnter the Rack number where you will keep it :~~~~~~~~$ ");
	scanf("%d",&rack);
	fflush(stdin);
	while(tr){	// to repeate the code to check date is valid or not
		printf("\nEnter the Expiry date of medicine (dd/mm/yyyy):~~~~~~~~$ ");
		scanf("%s",ex_date);	// getting date from user
		tr=validate_date(); // function for validation of date
		if(tr==1)	// to check date is valid or not
			printf("\t\t\t\t\t******__________Invalid date.__________******\n\n");
	}
	write_data();	// calling of fucntion to write data on .txt file

}
void input_medicine(){
	system("cls"); 
	printf("\t\t\t\t$$$$$$__________WELCOME TO MEDICAL SHOP__________$$$$$$\n\t\t\t\t\t     _______by M.Raj Yadav_______\n\n");
	int ch;
	char choice='y';
	while(1){	// for user's choise 
		printf("\n 1-------> One by one \n 2-------> More than one\n 3-------> Home\n\n");
		printf("\Enter your choice :~~~~~~~~$ ");
		fflush(stdin);
		scanf("%d",&ch);
		switch(ch){	// case according to user 
			case 1:
				get_data();	// calling the function to get data from user
				break;
			case 2:
				while(choice=='y' || choice=='Y'){		// to ask user to input more or not
					get_data();	// calling the function to get data from user
					printf("\nMore (y/n) :~~~~~~~~$ ");
					fflush(stdin);
					scanf("%c",&choice);
					
					
				}
				main();
				// to exit from the switch
			case 3:
				main(); // calling the main fucntion according to user's choice
			default:	// for wrong choice
				printf("\t\t\t******__________Oops!, Your choice was wrong so try again.__________******\n");		
		}
	}
	
	
}
void search_medicine(){
	system("cls");
	printf("\t\t\t\t$$$$$$__________WELCOME TO MEDICAL SHOP__________$$$$$$\n\t\t\t\t\t     _______by M.Raj Yadav_______\n\n");
	char ch, choice;
	 s_medicine[0]='\0';	// making it empty
	FILE *f;	// file pointer
	sr_flag=flag=0;		// flags are for certian situation
	int flag1=0;
	f = fopen("medical.txt","r");		//opening the .txt file in read mode
	fseek(f,90L,SEEK_SET);	// fixing the file cursur on a certain place
	ch=fgetc(f);
	if(ch==EOF){
		printf("\n\t\t   ******__________Oops!, There is no data, Please insert data first__________******\n\n");
		fclose(f);
		printf("\nPLease enter any key :~~~~~~~~$ ");
		getch();
		main();
	}
	fseek(f,91L,SEEK_SET);	// fixing the file cursur on a certain place
	ch=fgetc(f);
	if(ch==EOF){
		printf("\n\t\t   ******__________Oops!, There is no data, Please insert data first__________******\n\n");
		fclose(f);
		printf("\nPLease enter any key :~~~~~~~~$ ");
		getch();
		main();
		
	}
	printf("\n\t\t\t   ******__________Click 'n' if it was wrong choice__________****** \n\nEnter medicine name to search :~~~~~~~~$ ");
	fflush(stdin);	// flushing the buffer memory
	gets(s_medicine);
	
	if((s_medicine[0]=='n' ||	s_medicine[0]=='N') && s_medicine[1]=='\0' )
		main();
	
	fseek(f,0L,SEEK_SET);
	while((ch=fgetc(f))!=EOF)	// counting the line 
		if(ch=='\n')	// counting the line 
		flag++;			// to store file has how many line
	fseek(f,91,SEEK_SET);	// fixing the file cursur on a certain place
	for(i=1;i<flag;i++){	// for reading data line by line 
		fscanf(f,"%d%d%s%d%d%d%d%d%s",&sn,&rack,medicine,&leap,&l_size,&l_prize,&jar,&j_prize,ex_date);
		if(strcmpi(medicine,strlwr(s_medicine))==0){	// compaing the data 	
			show_data();	// calling the show function to show sesrched medicine
			flag1=1; 
			break;	// termination of loop
		}
		else{
			leap=l_size=l_prize=jar=j_prize=rack=0;	// making all variable empty
			medicine[0]='\0'; ex_date[0]='\0';
			sr_flag++;
		}
	}
	if(sr_flag!=0 && flag1!=1)
		printf("\n\t\t\t\t******__________Medicine did not found.__________******\n\n");
	else if(flag1==0)
		printf("\n\t\t\t\t******__________Medicine did not found.__________******\n\n");
	
	fclose(f);		// closing the file 
	printf("\nPLease enter any key character :~~~~~~~~$ ");
	getch();
	main();
}
void display_medicine(){
	system("cls");
	printf("\t\t\t\t$$$$$$__________WELCOME TO MEDICAL SHOP__________$$$$$$\n\t\t\t\t\t     _______by M.Raj Yadav_______\n\n");
	char ch;
	flag=0;
	FILE *f;
	f = fopen("medical.txt","r");	//opening the .txt file in read mode
	while((ch=fgetc(f))!=EOF)
		if(ch=='\n')
			flag++;
	fseek(f,90L,SEEK_SET);	// fixing the file cursur on a certain place
	ch=fgetc(f);
	if(ch==EOF){
		printf("\n\t\t   ******__________Oops!, There is no data, Please insert data first__________******\n\n");
		fclose(f);
		printf("\nPLease enter any key :~~~~~~~~$ ");
		getch();
		main();
	}
	fseek(f,91L,SEEK_SET);	// fixing the file cursur on a certain place
	ch=fgetc(f);
	if(ch==EOF){
		printf("\n\t\t   ******__________Oops!, There is no data, Please insert data first__________******\n\n");
		fclose(f);
		printf("\nPLease enter any key :~~~~~~~~$ ");
		getch();
		main();
		
	}fseek(f,91L,SEEK_SET);
	for(i=1;i<flag;i++){		// for reading data line by line 
		fscanf(f,"%d%d%s%d%d%d%d%d%s",&sn,&rack,medicine,&leap,&l_size,&l_prize,&jar,&j_prize,ex_date);		//reading data 
		show_data();	// calling the show function to show sesrched medicine
//		printf("S.No : %d \nRack No. : %d  \nMedicine Name : %s  \nTotal Leap : %d  \nLeap Size : %d \nLeap Prize : %d \nTotal Jar : %d	\nJar Prize : %d \nExpire Date : %s\n\n",sn,rack,medicine,leap,l_size,l_prize,jar,j_prize,ex_date);
	}
	fclose(f);
	printf("\nPLease enter any key character :~~~~~~~~$ ");
	getch();
	main();

}
void delete_data(int sn1){
	FILE *f,*t;
	char ch1;
	int count=0;
	f=fopen("medical.txt","r");	//opening the .txt file in read mode
	t=fopen("temp","w");
	fputs("\n",t);
	while((ch1=fgetc(f))!=EOF)
		if(ch1=='\n')
			count++;
	fseek(f,91,SEEK_SET);	// fixing the file cursur on a certain place
	for(i=1;i<count;i++){
		fscanf(f,"%d%d%s%d%d%d%d%d%s",&sn,&rack,medicine,&leap,&l_size,&l_prize,&jar,&j_prize,ex_date);
		fprintf(t,"%d\t\t%d\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n",sn,rack,medicine,leap,l_size,l_prize,jar,j_prize,ex_date);
		}
	fclose(f);
	fclose(t);
	f=fopen("medical.txt","w");		//opening the .txt file in write mode
	//	fputs("\nSn.	Rack_no.	medicine_name	tablets_leap	tablets_in_leap	leap_prize	jar	jar_prize	expire_date",f);
	fputs("Sn.	Rack_no.	medicine_name	tablets		tablets_in_leap		leap_prize	jar	jar_prize	expire_date\n",f);	// writing the field or colomn name  on the main file
	t=fopen("temp","r");
	
	
	fseek(t,2,SEEK_SET);	// fixing the file cursur on a certain place
		for(i=1;i<count;i++){
		
		fscanf(t,"%d%d%s%d%d%d%d%d%s",&sn,&rack,medicine,&leap,&l_size,&l_prize,&jar,&j_prize,ex_date);
			// for copying data into main file leaving the deleted rows and making right the row number or sn. number 
		if(sn>sn1)
			fprintf(f,"%d\t\t%d\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n",sn-1,rack,medicine,leap,l_size,l_prize,jar,j_prize,ex_date);
		else if(sn<sn1)
			fprintf(f,"%d\t\t%d\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n",sn,rack,medicine,leap,l_size,l_prize,jar,j_prize,ex_date);
	}
	fclose(f);
	fclose(t);
	remove("temp");	// deleting the temp file from harddisk.
	
}
void delete_medicine(){
	system("cls");
	printf("\t\t\t\t$$$$$$__________WELCOME TO MEDICAL SHOP__________$$$$$$\n\t\t\t\t\t     _______by M.Raj Yadav_______\n\n");
	char s_medicine[30],ch, choice;
	leap=l_size=l_prize=jar=j_prize=rack=flag=sr_flag=0;	// making all variable empty
	medicine[0]='\0'; ex_date[0]='\0';
	FILE *f;
	 flag=sr_flag=0;
	 int flag1;
	f = fopen("medical.txt","r");		//opening the .txt file in read mode
	fseek(f,90L,SEEK_SET);	// fixing the file cursur on a certain place
	ch=fgetc(f);
	if(ch==EOF){
		printf("\n\t\t   ******__________Oops!, There is no data, Please insert data first__________******\n\n");
		fclose(f);
		printf("\nPLease enter any key :~~~~~~~~$ ");
		getch();
		main();
	}
	fseek(f,91L,SEEK_SET);	// fixing the file cursur on a certain place
	ch=fgetc(f);
	if(ch==EOF){
		printf("\n\t\t   ******__________Oops!, There is no data, Please insert data first__________******\n\n");
		fclose(f);
		printf("\nPLease enter any key :~~~~~~~~$ ");
		getch();
		main();
		
	}
	fclose(f);
	printf("\n\t\t\t   ******__________Click 'n' if it was wrong choice__________****** \n\nEnter medicine name to delete :~~~~~~~~$ ");
	fflush(stdin);		// flushing the buffer memory
	gets(s_medicine);
	if((s_medicine[0]=='n' ||	s_medicine[0]=='N') &&s_medicine[1]=='\0' )
		main();
	
	f = fopen("medical.txt","r");	// same task as we done in search function
	fseek(f,90,SEEK_SET);
	while((ch=fgetc(f))!=EOF)
		if(ch=='\n')
		flag++;
	fseek(f,91,SEEK_SET);
	for(i=1;i<flag;i++){
		fscanf(f,"%d%d%s%d%d%d%d%d%s",&sn,&rack,medicine,&leap,&l_size,&l_prize,&jar,&j_prize,ex_date);
		if(strcmpi(medicine,strlwr(s_medicine))==0){
			delete_data(sn);	// calling the delete function to delete data with serial number 
			printf("\n\t\t\t  ######__________Medicine deleted from Rack no. %d.__________######\n\n",rack);
			flag1++;
		}
		else
			sr_flag++;		// flag to know data is deleted or not
	}
	if(sr_flag!=0 && flag1!=1)
		printf("\n\t\t\t\t******__________Medicine did not found.__________******\n\n");
	else if(flag1==1)
		printf("\n\t\t\t******__________Medicine did not found again.__________******\n\n");
	else if(flag1!=0 && sr_flag==0)
		printf("\n\t\t\t\t******__________Medicine did not found.__________******\n\n");
	printf("\nPLease enter any key :~~~~~~~~$ ");
	getch();
	main();
}
void make_bill(){
	system("cls");
	printf("\t\t\t\t$$$$$$__________WELCOME TO MEDICAL SHOP__________$$$$$$\n\t\t\t\t\t     _______by M.Raj Yadav_______\n\n");
	FILE *f, *s_f;
	int i, n, k;
	char ch, name[30];
	f = fopen("medical.txt","r");		//opening the .txt file in read mode
	fseek(f,90L,SEEK_SET);	// fixing the file cursur on a certain place
	ch=fgetc(f);
	if(ch==EOF){
		printf("\n\t\t   ******__________Oops!, There is no data, Please insert data first__________******\n\n");
		fclose(f);
		printf("\nPLease enter any key :~~~~~~~~$ ");
		getch();
		main();
	}
	fseek(f,91L,SEEK_SET);	// fixing the file cursur on a certain place
	ch=fgetc(f);
	ch=fgetc(f);
	if(ch==EOF){
		printf("\n\t\t   ******__________Oops!, There is no data, Please insert data first__________******\n\n");
		fclose(f);
		printf("\nPLease enter any key :~~~~~~~~$ ");
		getch();
		main();
		
	}
	fclose(f);
	printf("\n\t\t\t   ******__________Click 0 if it was wrong choice__________****** \n\nEnter total number of Medicine to be sold :~~~~~~~~$ ");
	scanf("%d",&n);
	if(n==0)
	main();
	printf("\nEnter buyer's name :~~~~~~~~$ ");
	fflush(stdin);
	gets(name);
	int quan[n],s_sn;
	float pay_prize=0;
	char medicine1[n][30];	
	for(i=0;i<n;i++){	// taking input from user
		printf("\nEnter Medicine name %d :~~~~~~~~$ ",i+1);
		fflush(stdin);
		scanf("%s",medicine1[i]);
		printf("Enter quantity :~~~~~~~~$ ");
		scanf("%d",&quan[i]);
		
	}
//	for(i=0;i<n;i++)
	//printf("medicine : %s\n",medicine1[i]);
	system("cls");
	printf("\t\t\t\t$$$$$$__________WELCOME TO MEDICAL SHOP__________$$$$$$\n\t\t\t\t\t     _______by M.Raj Yadav_______\n\n");
	printf("\t\t\t\t\t######__________Bill Window__________######\n\n");
	s_f = fopen("sold_medicine.txt","a+");
	long s_file_point;
		while((ch=getc(s_f))!=EOF){
			s_file_point=ftell(s_f);
		}
	fseek(s_f,s_file_point-1,0L);
	fscanf(s_f,"%d",&s_sn);
	fprintf(s_f,"\t %s\n",strlwr(name));
	fclose(s_f);
	current_date_();	// calling current date fucntion to get current date 
	printf("\n\t\t\t\t Name : %s\n",strupr(name));
	printf("\nMedicine Name\t\tPrize\t\tQuantity\tTotal\t\tExprire");
	for(i=0;i<n;i++){			// for making total bill of all medicine 
		int expired,found,less;
		float rate,total; 
		char ex_date1[11];
		flag=0;
		file_point=91L;
		f = fopen("medical.txt","r");	//to count the line 
		while((ch=fgetc(f))!=EOF)
		if(ch=='\n')
			flag++;							//to count the line
		//printf("\n%d",file_point);
			fseek(f,file_point,SEEK_SET);		// fixing the file cursur on a certain place
		for(k=0;k<flag;k++){			// for reading the data of a file line by line 
			file_point=ftell(f);		// storing the cursur possion for updating row by decreasing amount of piece 
			fscanf(f,"%d%d%s%d%d%d%d%d%s",&sn,&rack,medicine,&leap,&l_size,&l_prize,&jar,&j_prize,ex_date);		// reading the data

			if(strcmp(medicine,strlwr(medicine1[i]))==0){			// comparision of data 
				found=0;						// flag to indicate whether the data exits or not (for each data with the help of loop)
				break;			// breaking the second loop
			}
			else{
				found=1;		// indicates there is no such data 
				leap=l_size=l_prize=jar=j_prize=rack=0;		// making all variable empty
				medicine[0]='\0'; ex_date[0]='\0';
			}	
		}
		fclose(f);			// closing the file 
		//		printf("%d	\t%d\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t %s\n",sn,rack,medicine,leap,l_size,l_prize,jar,j_prize,ex_date);
		f=fopen("medical.txt","a");		// opening the file in read and write mood to update data 
		if( leap == 0 && l_size == 0 && found==0){		// to indicate it is tablets or jar
			if(jar>=quan[i]){
			
				if(comp_date(ex_date,current_date)>15){			// to check whether the medicne has expired or not
					expired=0;					// to indicate medicine has not expired 
					rate=(float)j_prize;				// getting the rate of the perticular medicine 
					total=(float)quan[i]*rate;		// calculating the rate of a medicine on the basis of piece 
					less=0;
					fseek(f,file_point+1,SEEK_SET);		// fixing the file cursur to update the selled medicine's data 
					if((jar-quan[i])!=0)
						fprintf(f,"%d\t\t%d\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n",flag,rack,medicine,leap,l_size,l_prize,jar-quan[i],j_prize,ex_date);	// updating the pertucular data by denreasing number of medicine
					fclose(f);
					delete_data(sn);
						
				}
				else
				expired=1;		// edicates the medicine has expired 
			}
			else
				less=1;
		}
		else if( leap != 0 && l_size != 0 && found==0){		// for tablets // all work is same as jar 
			if(leap>=quan[i]){
				if(comp_date(ex_date,current_date)>15){
					expired=0;
					rate=(float)l_prize/l_size;				
					total=(float)quan[i]*rate;
					less=0;
					fseek(f,file_point+1,SEEK_SET);
					if(leap-quan[i]!=0)
						fprintf(f,"%d\t\t%d\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n",flag,rack,medicine,leap-quan[i],l_size,l_prize,jar,j_prize,ex_date);
					fclose(f);
					delete_data(sn);
						
					
				}
				else
				expired=1;		// till here
			}
			else
				less=1;
		
		} 
					// closing the file
		fclose(f);
	//	printf("%d	   %d		%s		%d		%d		%d		%d	   %d		%s",sn,rack,medicine,leap,l_size,l_prize,jar,j_prize,ex_date);
		if(found==1)
			printf("\n%15s\t\t%4d\t\t%4d\t\t%4d\t\tNone\t\tNot found ",medicine1[i],0,0,0);
		else if(less==1){
			printf("\n%15s\t\t%4d\t\t%4d\t\t%4d\t\tNone\t\tLess in quantity",medicine1[i],0,0,0);
		}	
		else if(expired==1){
			printf("\n%15s\t\t%4d\t\t%4d\t\t%4d\t\tYes",medicine1[i],0,0,0);
		}
		else if(expired==0 && less==0){		// making the bill of not expired medicine 
			pay_prize+=total;
			printf("\n%15s\t\t%.2f\t\t%5d\t\t%.2f\t\tNot",medicine1[i],rate,quan[i],total);
			s_f = fopen("sold_medicine.txt","a");
			fprintf(s_f,"\t\t\t\t\t %s\t\t %5d\t\t %.2f\t\t %.2f\n",strlwr(medicine1[i]),quan[i],rate,total);
			fclose(s_f);
		}
		
	 
	}
	// Sn.\t Name_of_buyer\t\t medicine_name\t\t piece\t piece_prize\t total_prize\n
	if(pay_prize!=0){
		s_f = fopen("sold_medicine.txt","a");
		fprintf(s_f,"\t\t\t\t\t Payable_Total_Prize : %.2f\n\t\t\t\t\t\t Date : %s\n\n%d",pay_prize,current_date,s_sn+1);
		fclose(s_f);
	}	
	printf("\n\n\t\t\t\tTotal Prize : %.2f \n\n\n",pay_prize);		// printing the payable prize 
	printf("\nPLease enter any two key :~~~~~~~~$ ");
	getch();
	getch();
	main();
}
void create_file(){		// creats the main medical.txt file with field name when we will run the program first time 
	FILE *f;
	int rk_v;
	char rk[50];
	f = fopen("medical.txt","r+");
	if(f==NULL){
		f = fopen("medical.txt","w");	// file is created if file will not exist and fields are writting 
		fputs("Sn.	Rack_no.	medicine_name	tablets		tablets_in_leap		leap_prize	jar	jar_prize	expire_date\n",f);
	}
	fclose(f);
	f = fopen("medical.txt","r+");		// file is not created if it will exist, only field name will be added if it does not cotain
	fgets(rk,sizeof(rk),f);
	if(strcmp(rk,"\0")==0)
	{
		fputs("Sn.	Rack_no.	medicine_name	tablets		tablets_in_leap		leap_prize	jar	jar_prize	expire_date\n",f);		
	}
	fclose(f);
	
	
	f = fopen("sold_medicine.txt","r+");
	if(f==NULL){
		f = fopen("sold_medicine.txt","w");	// file is created if file will not exist and fields are writting 
		fputs("Sn.\t Name_of_buyer\t\t medicine_name\t\t piece\t piece_prize\t total_prize\n",f);
		fprintf(f,"%d",1);
	}
	fclose(f);
	rk[0]='\0';
	f = fopen("sold_medicine.txt","r+");		// file is not created if it will exist, only field name will be added if it does not cotain
	fseek(f,70L,0L);
	fscanf(f,"%d",&rk_v);
	if(rk_v!=1)
	{	
		fseek(f,0L,0L);
		fputs("Sn.\t Name_of_buyer\t\t medicine_name\t\t piece\t piece_prize\t total_prize\n",f);
		fprintf(f,"%d",1);	
	}
	fclose(f);
	
}
int validate_date(){
		char ex_date1[11],d_ck[5],fr;
		int i,j=-1;
		// to convert 1/12/2022 into 01/12/2022
		d_ck[0]=ex_date[0];
		d_ck[1]='\0';
		fr=ex_date[1];
		strcpy(ex_date1,ex_date);
		if(strcmp(d_ck,"9")<=0 && strcmp(d_ck,"1")>=0 && fr=='/'){
			ex_date[0]='0';
			for(i=1;i<=9;i++)
				ex_date[i]=ex_date1[i-1];
		}
			//end
		// to convert 12/1/2022 into 12/01/2022
		d_ck[0]=ex_date[3];
		d_ck[1]='\0';
		fr=ex_date[4];
		strcpy(ex_date1,ex_date);
		if(strcmp(d_ck,"9")<=0 && strcmp(d_ck,"1")>=0 && fr=='/'){
			for(i=0;i<=9;i++)
				if(i==3)
					ex_date[3]='0';
				else if(i<3)
					ex_date[i]=ex_date1[i];
				else
					ex_date[i]=ex_date1[i-1];
			ex_date[10]='\0';
		}
			//end
	//	printf("date = %s\n",ex_date);
		for(i=0;i<=9;i++){
			j++;
			d_ck[j]=ex_date[i];
			if(i==1){   // for date checking
				d_ck[2]='\0';
				fr=ex_date[i+1];
				if(strcmp(d_ck,"31")<=0 && strcmp(d_ck,"01")>=0 && fr=='/'){
					i++;
					j=-1;
				}
				else{
					return 1;
					break;
				}
			}	
			else if(i==4){	// for month checking
				d_ck[2]='\0';
				fr=ex_date[i+1];
				if(strcmp(d_ck,"12")<=0 && strcmp(d_ck,"01")>=0 && fr=='/'){
					i++;
					j=-1;
				}
				else{
					return 1;
					break;
				}	
			}
			else if(i==9){	// for year checking
				d_ck[4]='\0';
				if(strcmp(d_ck,"2050")<=0 && strcmp(d_ck,"2022")>=0){
					d_ck[0]='\0'; 
					return 0;
				}
				else{
					return 1;
					break;
				}
			}	
		}
}
void current_date_(){
	// the method to get current date in integer form 
	time_t t;
	t=time(NULL);
	struct tm tm = *localtime(&t);	// the tm structure is a predefine strucutre which is in-built with time.h file 
	//printf("%d/%d/%d",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
	
	
	// it is all about for conversion of integer date into string type date with "/" sign 
	int date[3],i,r,j=0;
	char cu_date[11],f_cu_date[11];
	date[0]=tm.tm_mday;
	date[1]=tm.tm_mon+1;
	date[2]=tm.tm_year+1900;
	for(i=0;i<3;i++){
		while(date[i]>0){
			r=date[i]%10;
			date[i]=date[i]/10;
			switch(r){
				case 0:
					cu_date[j++]='0';
					break;
				case 1:
					cu_date[j++]='1';
					break;
				case 2:
					cu_date[j++]='2';
					break;
				case 3:
					cu_date[j++]='3';
					break;
				case 4:
					cu_date[j++]='4';
					break;
				case 5:
					cu_date[j++]='5';
					break;
				case 6:
					cu_date[j++]='6';
					break;
				case 7:
					cu_date[j++]='7';
					break;
				case 8:
					cu_date[j++]='8';
					break;
				case 9:
					cu_date[j++]='9';
					break;
			}
		}
		cu_date[j++]='/';
	}
	cu_date[j-1]='\0';
	// switch case covertes it into a wrong format so i am making it the right formate 
	// switch case gives date eg. 15/12/2022 like 51/21/2202
	strcpy(ex_date,cu_date);
	if(tm.tm_mday<10 && tm.tm_mon<10){
		validate_date();			// for making 1/1/2022 into 10/10/2022
		// blew code for making 10/10/2202 into 01/01/2022
		f_cu_date[0]=ex_date[0];
		f_cu_date[1]=ex_date[1];
		f_cu_date[2]=ex_date[2];
		f_cu_date[3]=ex_date[3];
		f_cu_date[4]=ex_date[4];
		f_cu_date[5]=ex_date[5];
		f_cu_date[6]=ex_date[9];
		f_cu_date[7]=ex_date[8];
		f_cu_date[8]=ex_date[7];
		f_cu_date[9]=ex_date[6];
		f_cu_date[10]=ex_date[10];
	}
	else if(tm.tm_mday<10){
		validate_date();	// for making 1/11/2022 into 10/11/2022
				// blew code for making 10/11/2022 into 01/11/2022
		f_cu_date[0]=ex_date[0];
		f_cu_date[1]=ex_date[1];
		f_cu_date[2]=ex_date[2];
		f_cu_date[3]=ex_date[4];
		f_cu_date[4]=ex_date[3];
		f_cu_date[5]=ex_date[5];
		f_cu_date[6]=ex_date[9];
		f_cu_date[7]=ex_date[8];
		f_cu_date[8]=ex_date[7];
		f_cu_date[9]=ex_date[6];
		f_cu_date[10]=ex_date[10];	
	}
	else if(tm.tm_mon<10){
		validate_date();	// for making 23/1/2022 into 23/10/2022
				// blew code for making 23/10/2022 into 23/01/2022
		f_cu_date[0]=ex_date[1];
		f_cu_date[1]=ex_date[0];
		f_cu_date[2]=ex_date[2];
		f_cu_date[3]=ex_date[3];
		f_cu_date[4]=ex_date[4];
		f_cu_date[5]=ex_date[5];
		f_cu_date[6]=ex_date[9];
		f_cu_date[7]=ex_date[8];
		f_cu_date[8]=ex_date[7];
		f_cu_date[9]=ex_date[6];
		f_cu_date[10]=ex_date[10];
	}
	else{	//  given by switch like 51/21/2202  and it makes it like 15/12/2022
			
		f_cu_date[0]=ex_date[1];
		f_cu_date[1]=ex_date[0];
		f_cu_date[2]=ex_date[2];
		f_cu_date[3]=ex_date[4];
		f_cu_date[4]=ex_date[3];
		f_cu_date[5]=ex_date[5];
		f_cu_date[6]=ex_date[9];
		f_cu_date[7]=ex_date[8];
		f_cu_date[8]=ex_date[7];
		f_cu_date[9]=ex_date[6];
		f_cu_date[10]=ex_date[10];
	}
	
	
	strcpy(current_date,f_cu_date);	// to copy and make it global 
//	printf("\n%s",current_date);

}
int comp_date(char *ex_date, char *cr_date){  // user defined function for comparision of date 
	char v;
	int i,k,j,day,mon,year,date[2][3];
	for(k=0;k<2;k++)
		for(i=0;i<3;i++)
			date[k][i]=0;	
	for(k=0;k<2;k++)
		for(j=0;j<=9;j++){
			if(k==0)
				v=ex_date[j];
			else
				v=cr_date[j];
			if(j==0 || j==1)
			{
				i=0;
				goto switch1;
			}
			else if(j==3 || j==4)
			{
				i=1;
				goto switch1;
			}
			else if(j==6 || j==7 || j==8 || j==9)
			{
				i=2;
				goto switch1;
			}
				top:
			if(j==9)
				break;		
		}
		
	v='\0';
	switch1:
	switch(v){
		case '0':
			date[k][i]=10*date[k][i]+0;
			goto top;
		case '1':
			date[k][i]=10*date[k][i]+1;
			goto top;
		case '2':
			date[k][i]=10*date[k][i]+2;
			goto top;
		case '3':
			date[k][i]=10*date[k][i]+3;
			goto top;
		case '4':
			date[k][i]=10*date[k][i]+4;
			goto top;
		case '5':
			date[k][i]=10*date[k][i]+5;
			goto top;
		case '6':
			date[k][i]=10*date[k][i]+6;
			goto top;
		case '7':
			date[k][i]=10*date[k][i]+7;
			goto top;
		case '8':
			date[k][i]=10*date[k][i]+8;
			goto top;
		case '9':
			date[k][i]=10*date[k][i]+9;
			goto top;	
	}	
//	printf(" date1 : %d/%d/%d\n",date[0][0],date[0][1],date[0][2]);
//	printf(" date2 : %d/%d/%d\n",date[1][0],date[1][1],date[1][2]);
	day	= date[0][0]-date[1][0];
	mon	= date[0][1]-date[1][1];
	year= date[0][2]-date[1][2];
	//printf("%d %d %d",day,mon,year);
	day = day + (mon*30) + (year*364);
//	printf("\n%d",day);
return day;
}
void main(){
	system("cls");
	printf("\t\t\t\t$$$$$$__________WELCOME TO MEDICAL SHOP__________$$$$$$\n\t\t\t\t\t     _______by M.Raj Yadav_______\n\n");
	create_file();
	while(1){	// to reapeat task again untill user will want 
	// menu 
		int ch1=0;
		printf("\n 1-------> Insert medicine \n 2-------> Delete Medicine \n 3-------> Search medicine \n 4-------> Display all medicine \n 5-------> Make Bill \n 6-------> Exit\n\n");
		printf("Enter your  choice :~~~~~~~~$ ");
		scanf("%d",&ch1);
		switch(ch1){	
			// according to choice, function will be called 
			case 1 :
				fflush(stdin);
				input_medicine();
				
				break;
			case 2 :
				delete_medicine();
				break;
			case 3 :
				search_medicine();
				break;
			case 4 :
				display_medicine();
				break;
			case 5 :
				make_bill();
				break;
			case 6 :
				exit(1);
			default :		// to indicate wrong choice 
				printf("\t\t\t******__________Oops!, Your choice was wrong so try again.__________******\n"); 
				
	}
		}
	
}

/*
int reck(){ // for making rack number from the given rack range by user 
	FILE *f;
	int rk_v, cur_po;
	char rk[7];
	f = fopen("medical.txt","r+");
	if(f==NULL){
		f = fopen("medical.txt","w");
		fputs("rack = 0",f);
		fclose(f);
	}
	f = fopen("medical.txt","r+");
	fgets(rk,sizeof(rk),f);
//	printf("%s",rk);
	fseek(f,7,SEEK_SET);
	fscanf(f,"%d",&rk_v);
//	printf(" %d \n",rk_v);
//	fclose(f);
	if(rk_v==0)
	{
	//	f = fopen("medical.txt","r+");
		printf("Enter total number of Rack : ");
		scanf("%d",&rk_v);
		fseek(f,7,SEEK_SET);
//		fpos_t pos=3;
//		fsetpos(f,&pos);
	//	cur_po=ftell(f);
//		printf("\n cursur : %ld",cur_po);
		fprintf(f,"%d\n",rk_v);
		
	}	
	fclose(f);
	return rk_v;
}

*/
