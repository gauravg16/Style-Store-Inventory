//
//  main.cpp
//  Style Store Manageent
//
//  Created by Gaurav Gupta on 23/01/21.
//



#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<iostream.h>
class garment
{
 int id,cost;
 char t[15],co[20],cat[20];
 public:
 void gdata()
 {
  cout<<"enter id,cost,type,colour and category of garment"<<endl;
  cin>>id>>cost;
  gets(t);gets(co);gets(cat);
 }
void disp()
 {
  cout<<"id :"<<id<<endl<<"cost :"<<cost<<endl<<"type :"<<t<<endl<<"colour: "<<co<<endl<<"category: "<<cat<<endl;
 }
 char* rett()
 {
  return t;
 }
 char* retcol()
 {
  return co;
 }
 char* retcat()
 {
  return cat;
 }
 int retid()
 {
  return id;
 }
 int retcost()
 {
  return cost;
 }
};
int ans;
garment s1,s2;
fstream file,temp;
void create()
{
 file.open("a.dat",ios::out|ios::binary);
 do
 {
  s1.gdata();
  file.write((char*)&s1,sizeof(s1));
  cout<<"enter 1 to continue writting in file"<<endl;
  cin>>ans;
 }while(ans==1);
 file.close();
}
void display()
{
 file.open("a.dat",ios::in|ios::binary);
 while(file.read((char*)&s1,sizeof(s1)))
 {
  s1.disp();
  cout<<endl;
 }
 file.close();
}
void countcost()
{
 int c1=0,c2=0,c3=0;
 file.open("a.dat",ios::in|ios::binary);
 while(file.read((char*)&s1,sizeof(s1)))
 {
   if(s1.retcost()<499)
    {
     c1++;
    }
   if(s1.retcost()>499 && s1.retcost()<999)
   {
    c2++;
   }
   if(s1.retcost()>999 && s1.retcost()<1499)
    {
     c3++;
    }
  }
  file.close();
  cout<<"garments below Rs 499 : "<<c1<<endl<<"garments between Rs 499-999 : "<<c2<<endl<<"garments between Rs 999-1499 : "<<c3<<endl;
}
void countcolour()
{
 int c1=0;
 char sc[20];
 cout<<"enter the colour to be searched"<<endl;
 gets(sc);
 file.open("a.dat",ios::in|ios::binary);
 while(file.read((char*)&s1,sizeof(s1)))
 {
  if( strcmpi(s1.retcol(),sc)==0)
  {
   c1++;
  }
 }
 file.close();
 cout<<"number of garments of colour "<<sc<<" are -"<<c1<<endl;
}
void search()
{
 int k=0,sid,ch;char st[40];
 file.open("a.dat",ios::in|ios::binary);
 cout<<" enter "<<endl<<"1.search on basis of id"<<endl<<"2.search on basis of type"<<endl;
 cout<<"enter choice"<<endl;
 cin>>ch;
 if(ch==1)
 {
  cout<<"enter id to be searched"<<endl;
  cin>>sid;
  while(file.read((char*)&s1,sizeof(s1)))
  {
   if(s1.retid()==sid)
   {
    cout<<"id found"<<endl;
    s1.disp();
    k=1;
    break;
    }
  }
   if(k==0)
   {
   cout<<"id not found";
   }
 }
 else if(ch==2)
 {
  cout<<"enter the type to be searched"<<endl;
  gets(st);
  while(file.read((char*)&s1,sizeof(s1)))
  {
   if(strcmpi(s1.rett(),st)==0)
   {
    k=1;break;
   }
  }
  if(k==0)
  {
   cout<<"type not found"<<endl;
  }
  else
  {
   cout<<"type found "<<endl;
   s1.disp();
  }
 }
 file.close();
}
void editid()
{
 int eid;
 file.open("a.dat",ios::in|ios::binary);
 temp.open("b.dat",ios::out|ios::binary);
 cout<<"enter id to be edited"<<endl;
 cin>>eid;
 while(file.read((char*)&s1,sizeof(s1)))
 {
  if(s1.retid()==eid)
  {
   cout<<"enter new details :"<<endl;
   s1.gdata();
  }
  temp.write((char*)&s1,sizeof(s1));
 }
 temp.close();
 file.close();
 remove("a.dat");
 rename("b.dat","a.dat");

}
void editn()
{
 int er,r=0;
 file.open("a.dat",ios::in|ios::binary);
 temp.open("b.dat",ios::out|ios::binary);
 cout<<" enter record to be edited"<<endl;
 cin>>er;
 while(file.read((char*)&s1,sizeof(s1)))
 {
  r++;
  if(r==er)
  {
   cout<<"enter new details"<<endl;
   s1.gdata();
  }
  temp.write((char*)&s1,sizeof(s1));
 }
 temp.close();
 file.close();
 remove("a.dat");
 rename("b.dat","a.dat");

}
void deln()
{
 file.open("a.dat",ios::in|ios::binary);
 temp.open("b.dat",ios::out|ios::binary);
 int n,r=0;
 cout<<"enter the record to be deleted";
 cin>>n;
 while(file.read((char*)&s1,sizeof(s1)))
 {
  r++;
  if(n!=r)
  {
   temp.write((char*)&s1,sizeof(s1));
  }
 }
 temp.close();
 file.close();
 remove("a.dat");
 rename("b.dat","a.dat");
 cout<<"record has been deleted"<<endl;
 display();
}
void delcat()
{
 char dcat[20];
 file.open("a.dat",ios::in|ios::binary);
 temp.open("b.dat",ios::out|ios::binary);
 cout<<"enter the category to be deleted"<<endl;
 gets(dcat);
 while(file.read((char*)&s1,sizeof(s1)))
 {
  if(strcmpi(s1.retcat(),dcat)!=0)
  {
   temp.write((char*)&s1,sizeof(s1));
  }
 }
 file.close();
 temp.close();
 remove("a.dat");
 rename("b.dat","a.dat");
 cout<<"record has been deleted "<<endl;
 display();
}
void inslt()
{
 file.open("a.dat",ios::in|ios::binary);
 temp.open("b.dat",ios::out|ios::binary);
 cout<<"enter new details for insertion"<<endl;
 s2.gdata();
 while(file.read((char*)&s1,sizeof(s1)))
 {
  temp.write((char*)&s1,sizeof(s1));
 }
temp.write((char*)&s2,sizeof(s2));
temp.close();
file.close();
remove("a.dat");
rename("b.dat","a.dat");
cout<<"file has been inserted"<<endl;
display();
}
void inscost()
{
 int icost;
 cout<<"enter the cost for insertion"<<endl;
 cin>>icost;
 cout<<"enter new details for insertion "<<endl;
 s2.gdata();
 file.open("a.dat",ios::in|ios::binary);
 temp.open("b.dat",ios::out|ios::binary);
 while(file.read((char*)&s1,sizeof(s1)))
 {
   temp.write((char*)&s1,sizeof(s1));
   if(s1.retcost()==icost)
   {
    temp.write((char*)&s2,sizeof(s2));
   }
  }
  temp.close();
  file.close();
  remove("a.dat");
  rename("b.dat","a.dat");
  cout<<"file has been inserted"<<endl;
  display();
 }
void main()
{
 clrscr();
 int choice;char c;
 do
 {
  cout<<endl;
  cout<<"                            MENU"<<endl<<endl;
  cout<<"1.create file"<<"                         "<<"2.display records"<<endl;
  cout<<"3. count  on basis of cost"<<"            "<<"4. count on basis of colour"<<endl;
  cout<<"5. search in file"<<endl;
  cout<<"6. edit on basis of id"<<"                "<<"7. edit nth record"<<endl;
  cout<<"8. delete n th record"<<"                 "<<"9. delete a particular category"<<endl;
  cout<<"10. insert  at end of file"<<"            "<<"11. insert on basis of cost"<<endl;
  cout<<"enter your choice please"<<endl;
  cin>>choice;
  switch(choice)
  {
    case 1:create();break;
    case 2:display();break;
    case 3:countcost();break;
    case 4:countcolour();break;
    case 5:search();break;
    case 6:editid();break;
    case 7:editn();break;
    case 8:deln();break;
    case 9:delcat();break;
    case 10:inslt();break;
    case 11:inscost();break;
    default:cout<<"wrong choice"<<endl;
   }
   cout<<"\nif u want to go back to menu enter y"<<endl;
   cin>>c;
   }while(c=='y');
 getch();
 }


