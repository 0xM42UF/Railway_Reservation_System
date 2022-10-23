#include <conio.h>

#include <cstdio>

#include <iostream>

#include <string.h>

#include <cstdlib>

using namespace std;

static int p = 0;

class a

{

  char trainn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];

public:
    void display();

  void Booking();

  void allotment();

  void empty();

  void show();

//void avail();

  void position(int i);

}

train[10];

void vline(char ch)

{

  for (int i=80;i>0;i--)

  cout<<ch;

}

void a::display()
{
    cout<<"train name:"<<endl;
    cout<<"1.Dhaka express"<<endl;
    cout<<"2.Khulna express"<<endl;
    cout<<"3.Barishal express"<<endl;
    cout<<"4.Labukhali express"<<endl;
}
void a::Booking()

{

  cout<<"Enter train no: ";

  cin>>train[p].trainn;

  cout<<"\nEnter passenger's name: ";

  cin>>train[p].driver;

  cout<<"\nArrival time: ";

  cin>>train[p].arrival;

  cout<<"\nDeparture: ";

  cin>>train[p].depart;

  cout<<"\nFrom: \t\t\t";

  cin>>train[p].from;

  cout<<"\nTo: \t\t\t";

  cin>>train[p].to;

  train[p].empty();

  p++;

}

void a::allotment()

{

  int seat;

  char number[5];

  top:

  cout<<"train no: ";

  cin>>number;

  int n;

  for(n=0;n<=p;n++)

  {

    if(strcmp(train[n].trainn, number)==0)

    break;

  }

  while(n<=p)

  {

    cout<<"\nSeat Number: ";

    cin>>seat;

    if(seat>32)

    {

      cout<<"\nThere are only 32 seats available in this train.";

    }

    else

    {

    if (strcmp(train[n].seat[seat/4][(seat%4)-1], "Empty")==0)

      {

        cout<<"Enter passanger's name: ";

        cin>>train[n].seat[seat/4][(seat%4)-1];

        break;

      }

    else

      cout<<"The seat no. is already reserved.\n";

      }

      }

    if(n>p)

    {

      cout<<"Enter correct train no.\n";

      goto top;

    }

  }


void a::empty()

{

  for(int i=0; i<8;i++)

  {

    for(int j=0;j<4;j++)

    {

      strcpy(train[p].seat[i][j], "Empty");

    }

  }

}

void a::show()

{

  int n;

  char number[5];

  cout<<"Enter train no: ";

  cin>>number;

  for(n=0;n<=p;n++)

  {

    if(strcmp(train[n].trainn, number)==0)

    break;

  }

while(n<=p)

{

  vline('*');
   cout<<"\n";
  cout<<"train no: \t"<<train[n].trainn

  <<"\nDriver: \t"<<train[n].driver<<"\t\tArrival time: \t"

  <<train[n].arrival<<"\tDeparture time:"<<train[n].depart

  <<"\nFrom: \t\t"<<train[n].from<<"\t\tTo: \t\t"<<

  train[n].to<<"\n";

  vline('*');

  train[0].position(n);

  int a=1;

  for (int i=0; i<8; i++)

  {

    for(int j=0;j<4;j++)

    {

      a++;

      if(strcmp(train[n].seat[i][j],"Empty")!=0)

      cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<train[n].seat[i][j]<<".";

    }

  }

  break;

  }

  if(n>p)

    cout<<"Enter correct train no: ";

}

void a::position(int l)

{

  int s=0;p=0;

  for (int i =0; i<8;i++)

  {

    cout<<"\n";

    for (int j = 0;j<4; j++)

    {

      s++;

      if(strcmp(train[l].seat[i][j], "Empty")==0)

        {

          cout.width(5);

          cout.fill(' ');

          cout<<s<<".";

          cout.width(10);

          cout.fill(' ');

          cout<<train[l].seat[i][j];

          p++;

        }

        else

        {

        cout.width(5);

        cout.fill(' ');

        cout<<s<<".";

        cout.width(10);

        cout.fill(' ');

        cout<<train[l].seat[i][j];

        }

      }

    }

  cout<<"\n\nThere are "<<p<<" seats empty in train No: "<<train[l].trainn;

  }

/*void a::avail()
{
  for(int n=0;n<p;n++)
  {
    vline('*');
    cout<<"train no: \t"<<train[n].trainn<<"\nDriver: \t"<<train[n].driver
    <<"\t\tArrival time: \t"<<train[n].arrival<<"\tDeparture Time: \t"
    <<train[n].depart<<"\nFrom: \t\t"<<train[n].from<<"\t\tTo: \t\t\t"
    <<train[n].to<<"\n";
    vline('*');
    vline('_');
  }
}
*/

int main()

{
  /*  cout.width(5);
          cout.fill(' ');
          cout<<"INDIAN RAILWAYS";
          cout.width(10);
          cout.fill(' ');
*/

system("cls");

int w;

while(1)

{

    //system("cls");

  cout<<"\n\n\n\n\n";

  cout<<"\t\t\t1.display\n\t\t\t"
  <<"2.Booking\n\t\t\t"

  <<"3.Reservation\n\t\t\t"

  <<"4.Show\n\t\t\t"

  //<<"4.trains Available. \n\t\t\t"

  <<"5.Exit\n\t\t\t"
  ;

  cout<<"\n\t\t\tEnter your choice:-> ";

  cin>>w;

  switch(w)

  {
    case 1:  train[0].display();
    break;

    case 2:  train[p].Booking();

      break;

    case 3:  train[p].allotment();

      break;

    case 4:  train[0].show();

      break;

   // case 4:  train[0].avail();

    //  break;

    case 5:  exit(0);
    break;


  }

}
//cout.width(10);
//cout.fill('*');
//cout<<"\n";

//cout<<"\n";
//cout.width();
//cout.fill('*');

return 0;

}
