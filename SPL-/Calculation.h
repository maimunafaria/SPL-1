
using namespace std;
void calculation(int i, int j,int a,int b ,int ed)
{  //i and j are the file number , a and b are the string length of the files
     // and ed is the edit distance betweeen them.
        int maxlength;
        if (a>=b)
        {
            maxlength=a;
        }
        else
        {
            maxlength=b;
        }
        double percentage;
        percentage=(double(maxlength)-double(ed))/double(maxlength)*100;

        cout<<"\t\t\t"<<" Percentage of code clone between "<<"\t\t"<<endl;
        cout<<"\t\t\t"<<"    File No: "<<i<< " and " << "File No: "<<j<<"\t\t"<<endl;
        cout<<"\t\t\t\t"<< " is " <<percentage<< "%"<<"\t\t\n"<<endl;

}
