#include<iostream>
#include<sstream>
#include<ostream>
#include<vector>
#include<list>
#include<string>
#include<fstream>
#include<algorithm>
using namespace std;

class Hash
{
public:
	
	Hash(int &a):size(a),buckets((a/2)+173)
	{
		ab.resize(buckets);
	
	}
	~Hash()
	{
	for(int i=0; i<buckets; i++)
	{
	ab[i].clear();
	}

	}
	int hashfun(string &a)
	{
		int total=0;
		for(int i=0; i<a.length(); i++)
		{
			total = total +(23^i)*a[i]*(127^i)+67*(a[a.length()-1]*(56^i));//feeble attempt to make a good hash function, as it stands only gives me 87% distribution
		}

		 total = total % buckets;
		 return total;
		
		
	}

	void insert(string &a)
	{
		int x=hashfun(a);
		ab[x].push_back(a);
	}

	bool contains(string &a)
	{
		int x=hashfun(a);
		 list<string>::iterator iter = ab[x].begin();
		 while (iter != ab[x].end())
		 {
			 if(*iter==a)
			 {return true;}
			 iter++;
		 }
		 return false;
	}
	 
	int empty()
	{	int count=0;
		for (int i=0; i<30197; i++)
		{

			if(ab[i].empty())
			{count++;}
		}
		return count;
	}

	


private:
	int size;
	int buckets;
	vector<list<string> > ab;
	
	
};

void spellCheck(istream& inf, istream& wordlistfile, ostream& outf)
{//create hashtable
	
	//parsing wordlist
	string line; int x=0; 
	getline(wordlistfile, line);
	int val;
	stringstream sb;
		sb<<line;
		sb>>val;
	Hash  a(val);
	while( ! wordlistfile.eof() )
	{	
		getline(wordlistfile, line);
		
			transform(line.begin(), line.end(), line.begin(),(int (*)(int))tolower);
			a.insert(line);

	}


	while(!inf.eof())
	{
	//parse program add line
		getline(inf, line);
		vector<string> words;
	stringstream ss;
	string type;
	ss<<line;
	//parse input
	while(!ss.eof())
    {
   ss>>type;
 
  transform(type.begin(), type.end(), type.begin(),(int (*)(int))tolower);
   words.push_back(type);
   
    }

	
		for(int i=0; i<words.size(); i++)
		{	vector<string> suggest;
			if(!a.contains(words[i]))
			{//make suggestions  //DELTE ONE CHAR?
				 string temp=words[i];
				
			//swapping suggest
			for(int z=1; z<temp.size(); z++)
			{
				string sug1="";
				for(int j=0; j<temp.size(); j++)
				{	if(j!=z-1)
					{sug1+=temp[j];}
					else
					{sug1+=temp[j+1]; sug1+=temp[j]; j++;}

				}
				if(a.contains(sug1))
				{suggest.push_back(sug1);}
			}
				

			//inserting suggest
			for(int j=0; j<=temp.size(); j++)
			{
				for(int z=0; z<26; z++)
					{
						string sug2="";

						for(int k=0; k<j; k++)
						{sug2+=temp[k];}


						char letter='a'+z;
						sug2+=letter;

						for(int p=j; p<temp.size(); p++)
						{sug2+=temp[p];}
						
						if(a.contains(sug2))
							{suggest.push_back(sug2);}
					}
				

			}
			 //delete each char once
				for(int k=0; k<temp.size();k++)
				{string sug="";
					for(int j=0; j<temp.size();j++)
					{
						if(j!=k)
						{sug+=temp[j];}
					}
					
					if(a.contains(sug))
					{suggest.push_back(sug);}
				}

			//replace each character
				for(int j=0; j<temp.size(); j++)
				{	
					for(int z=0;z<26; z++)
					{string sug3="";

						for(int k=0; k<j; k++)
						{sug3+=temp[k];}

						char letter='a'+z;
						sug3+=letter;
						for(int p=j+1; p<temp.size(); p++)
						{sug3+=temp[p];}

						if(a.contains(sug3))
						{suggest.push_back(sug3);}

					}

				}

			//split sugg
				for(int j=0; j<temp.size()-1; j++)
				{	string suga=""; string spice="";
					
					for(int k=0; k<=j; k++)
					{suga+=temp[k];}

					for(int z=j+1; z<temp.size(); z++)
					{
						spice+=temp[z];
					}

					if(a.contains(suga) && a.contains(spice))
					{
						suggest.push_back(suga+" "+spice);
					}


				}

				outf<<line<<endl;
				transform(words[i].begin(), words[i].end(), words[i].begin(),(int (*)(int))toupper);
				outf<<"     word not found: "<<words[i]<<endl;//suggestions
				outf<<"  perhaps you meant:"<<endl;
				sort(suggest.begin(), suggest.end());
				suggest.erase( unique( suggest.begin(), suggest.end() ), suggest.end() );

				for(int g=0; g<suggest.size(); g++)
				{	transform(suggest[g].begin(), suggest[g].end(), suggest[g].begin(),(int (*)(int))toupper);
					outf<<"          "<<suggest[g]<<endl;
				}
				outf<<endl;
			}
		}
	}
		
}

int main()
{
	ifstream infile("wordlist.txt");
	ifstream input("input.txt");
	spellCheck(input,infile, cout);
	
}