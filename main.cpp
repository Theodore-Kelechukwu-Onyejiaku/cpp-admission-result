//Including Headers
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>

//Using standard library
using namespace std;

//Start Main function
int main()
{

    std::string line_; //string for each line of text file
    ifstream file_("result.txt"); //The file the program will read from
    ofstream fout; //The file that will be written to
    fout.open("admission.txt"); //Opening the file

    //Creating variables and some initializations
    int id, aggregate;
    int count = 0;
    std::string last_name;
    std::string first_name;
    std::string o_level;
    std::string utme;

    //If the file opens
    if(file_.is_open())
    {
        //What to display on the console
        std::cout<<"Please open the admission.txt file to see the written file"<< endl;
        std::cout<<"List of students admitted to the faculty of Law:"<< endl;
        std::cout<<endl;
        std::cout<<endl;
        std::cout<<"LastName  FirstName  Aggregate_Score" <<endl;

        //Here as we loop through each line of our result.txt file do the following:
        while(file_ >> id >> last_name >> first_name >> o_level >> utme >> aggregate){

            //If the aggregate score is greater than or equal to 50
            if(aggregate >= 50 ){
                    count++;// Increase counter by one

                    //This prints to the console
                    std::cout<< count << "  " <<last_name <<"  " << first_name << "  " << aggregate << endl;

                    //Writing result to our admission.txt file
                    fout << count << "  " <<"\t" <<last_name <<"  " << first_name << "  " << aggregate <<  endl;
            }
        }

        //Closing the files while we are done reading and writing to them
        file_.close();
        fout.close();
    }

    //If there is error due to opening of the file: do the following:
    else
        //Print this to the console
        std::cout<<"File is not open"<< "\n";
        std::cin.get();

        //end program
        return 0;
}
