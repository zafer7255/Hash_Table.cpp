#include<iostream>

using namespace std;

template<class T , class T1 , size_t size>
class Hash_Table
{
  /// We need to use here structure because in hashing table there is two data type Key And Value
  struct HashNode
  {
     T key;
     T1 value;
     bool occupied;
     HashNode() : occupied(false) {} // Assign Occupied as a false first
  };
   ///Let's Make Array of HashNode Structure Each blocks have the key and Value That we need
   HashNode Array[size] = {};

   ///The hash function in the provided code calculates the hash code for a given key of type T
   size_t hash(const T& key)
   {
     return std::hash<T>{}(key)%size;///function object to generate the hash code for the given key. 
   }
  
   public:

   void insert(const T& key , const T1& value)
   {
     size_t Index = hash(key);
     while (Array[Index].occupied)
     {
        if (Array[Index].key == key)
        {
            cout<<"Key Already Exist Update value"<<endl;
            Array[Index].value = value;
            return;
        }
        Index = Index+1%size;
     }
     Array[Index].key = key;
     Array[Index].value = value;
     Array[Index].occupied = true;
   }

   T1 search(const T& key)
   {
       int value;
       size_t Index = hash(key);
       while (Array[Index].occupied)
       {
         if (Array[Index].key == key)
         {
           value = Array[Index].value;
           return value;
         }
           Index = Index+1%size;
       }
        
        cout<<"There is no matching key in your hashing table "<<endl;
        return 0;
   }

   void remove(const T& key)
   {
    size_t Index = hash(key);
    while (Array[Index].occupied)
    {
       if (Array[Index].key == key)
       {
          Array[Index].occupied = false;
          return;
       }
       Index = Index+1%size;
    }

    cout<<"There is no "<<key<<" key"<<endl; 
    return;
   }

   void Print_All()
   {
    int i = 0;
     while (i<size)
     {
       cout<<"Key = |"<<Array[i].key<<" |";
       cout<<"Value = "<<Array[i].value;
       cout<<endl;
       i++;
     }
     
   }
};

int main()
{
  system("clear");
  Hash_Table<string,int,3>hashtable;
  hashtable.insert("Zafer",1);
  hashtable.insert("Mairaj",2);
  hashtable.insert("Akop",3);
  
  int value = hashtable.search("Zafer");
  cout<<"Value of Zafer is "<<value<<endl;

  hashtable.Print_All();
};
