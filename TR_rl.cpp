
/* Changed command line processing interface compared to v2 */

#include <unistd.h>
#include <stdio.h>

#include <fstream>
#include <string>
#include <string.h>
#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;
 
int main( int argc , char** argv ) {


   char fName[1000]="", fff[1000]="", RL_str[10];
   int L=300; //read length, should be provided as an input, default 150
   
  if (optind >= argc) {
        fprintf(stderr, "Expected area_file(*ra) read_length\n");
        fprintf(stderr, "Usage: area_file(*ra) read_length\n");
        exit(EXIT_FAILURE);
    }  

  if (argc < 2) {
        fprintf(stderr, "Expected area_file(*ra) and read_length\n");
        fprintf(stderr, "Usage: area_file(*ra) read_length\n");
        exit(EXIT_FAILURE);
    }  

   //strncat(fname,"",0);
   strncat(fName,argv[optind],strlen(argv[optind]));
   //printf ("fName=%s argv[2] = %s\n",fName,argv[2]);

   L=atoi(argv[2]);
   printf("L=%d\n",L);
      
   std::ifstream area_file( fName );
   if (!area_file) {
	fprintf(stderr, "Can't open input file %s\n",fName);	
        exit(EXIT_FAILURE);
    }

   std::string line;
   string trans="", trans_pred="", areas;
   int linecount=0;
   float rate, area, width, area_sum=0;

   sprintf(fff, "%sate_rl", fName);
   std::ofstream outfile(fff);
   printf("out=%s",fff);

    while ( getline( area_file , line ) ) {
	 //std::cout << linecount << ": " << line << '\n' ;//supposing '\n' to be line end
	 //linecount++ ;
	 stringstream ss(line);
         getline(ss,trans, '\t');
	 //	cout << "Transcript: " << trans << " trans_pred: "<<trans_pred<<endl;
         getline(ss,areas, '\t');
	 area=atof(areas.c_str());
         //       cout << "area: " << area <<endl;
         //getline(ss,widths, '\t');
         //width=atof(widths.c_str());
         //       cout << "width: " << width <<endl;

        if(trans_pred != trans) 
         { 
          rate=area_sum/L;
                        
          if(trans_pred!="") outfile << trans_pred << "\t" << rate << endl;   
           area_sum=area;
	 }
        else
            area_sum+=area;


         trans_pred=trans;
        }

   //process last record
        rate=area_sum/L;
        outfile << trans_pred << "\t" << rate << endl;   

   outfile.close();
   area_file.close();
  cout << endl << "END";
}
