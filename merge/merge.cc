
#include "merge.hh"

template <class CARRY>
merge<CARRY>::merge(std::vector<double>* fitness){

  this->X = fitness;

  this->reorder.resize(this->X->size());
  
}

template <class CARRY>
merge<CARRY>::~merge(){}

template <class CARRY>
void merge<CARRY>::AddCarry(std::vector<CARRY>* carry){

  if (carry->size() != this->X->size()){return;}

  this->carries.push_back(carry);
  
}

template <class CARRY>
void merge<CARRY>::Sort(){
  for (int i = 0; i < this->reorder.size(); ++i){
    this->reorder[i] = i;
  }
  this->MergeSort(0,this->X->size() - 1);
}


template <class CARRY>
void merge<CARRY>::MergeSort(unsigned int start, unsigned int end){

  if (end - start <= 0){
    return;
  }else if (end - start == 1){
    if ((*this->X)[this->reorder[end]] < (*this->X)[this->reorder[start]]){
      this->reorder_storage[0] = this->reorder[start];
      this->reorder[start] = this->reorder[end];
      this->reorder[end] = this->reorder_storage[0];
    }
  }else{
    int biggest_two = pow(2,log(end - start + 1)/log(2));
    this->MergeSort(start, biggest_two/2);
    this->MergeSort(biggest_two/2+1, end);
    int lead_1 = 0, lead_2 = biggest_two/2+1, placement = start;
    for (int i = start; i < lead_2; ++i){
      this->reorder_storage[i - start] = this->reorder[i];
    }

    while (lead_1 < biggest_two/2+1){
      if (lead_2 > end){
	for (int i = placement; i <= end; ++i){
	  this->reorder[i] = this->reorder_storage[lead_1];
	  lead_1++;
	}
	break;
      }

      if ((*this->X)[this->reorder[lead_1]] < (*this->X)[this->reorder[lead_2]]){
	this->reorder[placement] = this->reorder_storage[lead_1];
	lead_1++;
      }else{
	this->reorder[placement] = this->reorder[lead_2];
	lead_2++;
      }
      placement++;
    }
  }
  
}




