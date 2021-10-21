#include"Queue.hpp"
#include<iostream>
#include"utility.hpp"

using namespace std;


Queue::Queue()
/*
Post: The Queue is initialized to be empty.
*/
{
   count = 0;
   rear = maxqueue - 1;
   front = 0;
}


bool Queue::empty() const
/*
Post: Return true if the Queue is empty, otherwise return false.
*/
{
   bool success=true;
   if(count!=0)
   {
     success=false;
   }
   return success;
}


Error_code Queue::append(const Queue_entry &item)
/*
Post: item is added to the rear of the Queue. If the Queue is full
return an Error_code of overflow and leave the Queue unchanged.
*/

{
   if (count >= maxqueue) return overflow;
   count++;
   rear = ((rear + 1) == maxqueue) ? 0 : (rear + 1);
   entry[rear] = item;
   return success;
}


Error_code Queue::serve()
/*
Post: The front of the Queue is removed. If the Queue
is empty return an Error_code of underflow.
*/

{
   if (count <= 0) return underflow;
   count--;
   front = ((front + 1) == maxqueue) ? 0 : (front + 1);
   return success;
}


Error_code Queue::retrieve(Queue_entry &item) const
/*
Post: The front of the Queue retrieved to the output
      parameter item. If the Queue is empty return an Error_code of underflow.
*/

{
   if (count <= 0) return underflow;
   item = entry[front];
   return success;
}

bool Queue::full() const
{
 bool success= true;
 if(count == maxqueue) 
 {
   cout<<"full run"<<endl;
   success=false;
 }
 return success;
}

int Queue::size() const
{
    return count;
}

void Queue::clear()
{
  while(!empty())
  {
     serve();
  }
}

// i = ((i + 1) == max) ? 0 : (i + 1);
// if ((i + 1) == max) i = 0; else i = i + 1;
// i = (i + 1) % max;

Error_code Queue::serve_and_retrieve(Queue_entry &item)
{

  if(count<0) return underflow;
  item=entry[front];
  cout<<entry[front];
  if(count<=0) return underflow;
  count--;
  front = ((front + 1) == maxqueue) ? 0 : (front + 1);

 return success;
}