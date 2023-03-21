/************************************************************
*
*
********************************************************** /* */




/************************************************************
*
*
********************************************************** /* */
typedef struct Date
{
	int month;
	int year;
	
}date;

/************************************************************
*
*
********************************************************** /* */
date* createDate(int month, int year)
{
	date* local = (date*)	calloc( sizeof(date) , 1 );   	

	local->month = month;
	local->year = year;
	
	return local;
}


/************************************************************
*
*
********************************************************** /* */
void freeDate(date* current)
{
	current->month = rand();
	current->year = rand();	
	free(current);
	return;
}


/************************************************************
*
*
********************************************************** /* */
void printDate(date* current)
{
	printf("%2d/20%2d", current->month, current->year);
}

//char* getStringDate(date* current)
//{
     //char* stringDate = (char*) calloc( sizeof(char), 20);
    // construct a strong to return a the date - call it stringDate
	//return stringDate;
//}



