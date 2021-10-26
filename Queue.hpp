#include"Utility.hpp"
#include"Plane.hpp"

typedef Plane Queue_entry;
const int maxqueue=100;

class Queue {
protected:
   int count;
   int front, rear;
   Queue_entry entry[maxqueue];
public:
   Queue();
   bool empty() const;
   Error_code append(const Queue_entry &x);
   Error_code serve();
   Error_code retrieve(Queue_entry &x) const;
   bool full() const;
   int size() const;
   void clear();
   Error_code serve_and_retrieve(Queue_entry &item);
};

