#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}


// WRITE YOUR CODE HERE
/**
  * Adds a new value to the back of the list
  *   - MUST RUN in O(1)
  */

std::string* ULListStr::getValAtLoc(size_t loc) const{
  //string* retval = nullptr;
  if (loc >= size_ || loc < 0){
    return nullptr;
  }
  Item *curr = head_;
  // keep track of how many elements
  unsigned int loc_remaining = loc;
  // curr item has loc range [0, last-first]
  // if(while) not in range:
    // loc_remaining  -= (last - first)
    // curr = curr->next
  // accumulated + (curr last - curr first)

	// makes sure you're at the correct item
  while (curr -> last - curr -> first <= loc_remaining){
    loc_remaining  -= (curr -> last - curr -> first);
    curr = curr->next;
  }
	// return address
  return &curr->val[curr -> first + loc_remaining];

}
void ULListStr::push_back(const std::string& val){
  // check if entire thing is empty
  if (empty()){
		// create new head
    head_ = new Item();
		// set tail = to head
		tail_ = head_;
		// set value equal
    head_ -> val[head_ -> first] = val;
		// move head over
    head_ -> last++;
    size_++;
  }

	// this is if you're at the last value
  else if (tail_ -> last == ARRSIZE){ // check if last value
    Item *temp = new Item();
    temp -> val[temp -> first] = val;
    temp -> last++;
    temp -> prev = tail_;
    tail_ -> next = temp;
		// set tail = to last value
    tail_ = temp;
    temp -> next = NULL;
		// increment size of whole array
    size_++;
  }
  
  else{
    tail_ -> val[tail_ -> last] = val;
		tail_->last++;
		// increment size of whole array
    size_++;
  }

}

/**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::pop_back(){
  if (!empty()){ 
    if ((tail_ -> last - tail_ -> first) == 1){ // fix this
			// if only one value in list
      if (head_ == tail_){
				// delete head which also deletes tail
				delete head_;
				// set head and tail = to null
				head_ = NULL;
				tail_ = NULL;
			}
			else{
				// set temporary value = to tail 
				Item *temp = tail_;
				tail_ = tail_ -> prev;
				delete temp;
				// set next value of tail = to null
				tail_ -> next = nullptr;
			}
    }
    else{
			//decrement tail value
      tail_ -> last--;
    }
		// decrement size
    size_--;
  }
}

/**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */
void ULListStr::push_front(const std::string& val){
	// if head is null, thing is empty so add new item
	if (head_== nullptr){
    head_ = new Item();
    tail_ = head_;
    head_ -> val[ARRSIZE-1] = val;
    head_ -> last = ARRSIZE;
		head_->first = ARRSIZE-1;
  }
	// if first value = 0
  else if (head_ -> first == 0){
		Item *start = new Item();
		start ->val[ARRSIZE-1] = val;
		start -> last = ARRSIZE;
		start -> first = ARRSIZE-1;
		head_ -> prev = start;
		start -> next = head_;
		head_ = start;
		head_ -> prev = NULL;
	}
	// if not null but first value is not 0
	else{
		head_ -> first--;
		head_ -> val[head_ -> first] = val;
	}
	// increment size
  size_++;
}

/**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::pop_front(){
	// check if thing is not empty
  if (!empty()){
    if (head_ -> last - head_ -> first <= 1){
			if (head_ == tail_){
				// delete head which also delete tail
				delete head_;
				// delete head and tail
				head_ = NULL;
				tail_ = NULL;
			}
			else{
				Item *temp = head_;
				head_ = temp -> next;
				delete temp;
				head_ -> prev = NULL;
			}
    }
    else{
			// move head
      head_ -> first++;
    }
		// decrement size
    size_--;
  }
}
std::string const & ULListStr::front() const{
	return head_ -> val[head_ -> first];
}
std::string const & ULListStr::back() const{
	return tail_ -> val[tail_ -> last - 1];
}



void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
