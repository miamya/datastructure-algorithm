#include <iostream>

void printOriginalArray(int *arr, int insertNumber){
   std::cout << "Original array is: [";
   for(int x = 0; x<insertNumber; x++) {
           int y = insertNumber-1;
           if(x < y){
               std::cout << arr[x] << ", ";
           }
        else{
            std::cout << arr[x];
        }
   }
   std::cout << "]";
}

void printModifiedArray(int *arr, int insertNumber){
   std::cout << "Array after sorting is: [";
   for(int x = 0; x<insertNumber; x++) {
           int y = insertNumber-1;
           if(x < y){
               std::cout << arr[x] << ", ";
           }
        else{
            std::cout << arr[x];
        }
   }
   std::cout << "]";
}

void mergeArrayAsc(int *arr, int left, int mid, int right){
	int x, y, z, numberLeft, numberRight;
	//Size of left & right subarray
	numberLeft = mid-left+1;
	numberRight = right-mid;
	int leftArr[numberLeft], rightArr[numberRight];
	//Insert to left & right subarray
	for(x = 0; x<numberLeft; x++)
		leftArr[x] = arr[left+x];
	for(y = 0; y<numberRight; y++)
		rightArr[y] = arr[mid+1+y];
	
	x = 0;
	y = 0;
	z = left;
	//Merge subarray to array
	while(x < numberLeft && y < numberRight){
		if(leftArr[x] <= rightArr[y]){
			arr[z] = leftArr[x];
			x++;
		} else{
			arr[z] = rightArr[y];
			y++;
		}
		z++;
	}
	//Add extra space to left array
	while(x < numberLeft){
		arr[z] = leftArr[x];
		x++;
		z++;
	}
	//Add extra space to right array
	while(y < numberRight){
		arr[z] = rightArr[y];
		y++;
		z++;
	}
}
void mergeArrayDesc(int *arr, int left, int mid, int right){
	int x, y, z, numberLeft, numberRight;
	//Size of left & right subarray
	numberLeft = mid-left+1;
	numberRight = right-mid;
	int leftArr[numberLeft], rightArr[numberRight];
	//Insert to left & right subarray
	for(x = 0; x<numberLeft; x++)
		leftArr[x] = arr[left+x];
	for(y = 0; y<numberRight; y++)
		rightArr[y] = arr[mid+1+y];
	
	x = 0;
	y = 0;
	z = left;
	//Merge subarray to array
	while(x < numberLeft && y < numberRight){
		if(leftArr[x] >= rightArr[y]){
			arr[z] = leftArr[x];
			x++;
		} else{
			arr[z] = rightArr[y];
			y++;
		}
		z++;
	}
	//Add extra space to left array
	while(x < numberLeft){
		arr[z] = leftArr[x];
		x++;
		z++;
	}
	//Add extra space to right array
	while(y < numberRight){
		arr[z] = rightArr[y];
		y++;
		z++;
	}
}

void divideArray(int *arr, int left, int right, int menu){ //Divide array into two halves
      int mid;
      if(left < right){ //Divides until index = 0 only
      	int mid = left+(right-left)/2;
      	divideArray(arr, left, mid, menu);
      	divideArray(arr, mid+1, right, menu);
      	if(menu == 1){
      		mergeArrayAsc(arr, left, mid, right);
		}
		if(menu == 2){
			mergeArrayDesc(arr, left, mid, right);
		}
	  }  
}

int binarySearchAsc(int arr[], int insertNumber, int searchValue){
    int left,right,mid;
    left=0;
    right=insertNumber-1;
    while(left<=right)
        {
            mid=(left+right)/2;
            if(searchValue==arr[mid])
            return mid;
            else if(searchValue>arr[mid])
            right=mid-1;
            else
            left=mid+1;
        }
    return -1;
    }
int binarySearchDesc(int arr[], int insertNumber, int searchValue){
    int left,right,mid;
    left=0;
    right=insertNumber-1;
    while(left<=right)
     {
            mid=(left+right)/2;
            if(searchValue==arr[mid])
            return mid;
            else if(searchValue<arr[mid])
            right=mid-1;
            else
            left=mid+1;
        }
    return -1;
    }

void binarySearchValue(int arr[], int insertNumber, int searchValue, int result){
	if(arr[0] <= arr[insertNumber-1]){
		result = binarySearchAsc(arr, insertNumber, searchValue);
	}else if(arr[0] >= arr[insertNumber-1]){
		result = binarySearchDesc(arr, insertNumber, searchValue);
	}
	std::cout << std::endl;
	if(result == -1){
		std::cout << "The number " << searchValue << " is not found. " << std::endl; 
	}else{
	    std::cout << arr[result] << " is found at position " << result+1 << std::endl; 
	}
}

int linearSearch(int arr[], int insertNumber, int searchValue){
        int i;
        for(i=0;i<insertNumber;i++)
        {
            if(arr[i]==searchValue)
             return i;
        }    
        return -1;
        }

void sequentialSearchValue(int arr[], int insertNumber, int searchValue, int result){
	result = linearSearch(arr, insertNumber, searchValue);
	if(result >= 0){
		std::cout << arr[result] << " is found at index number " << result+1 << std::endl; 
	}else{
		std::cout << "The number " << searchValue << " is not found. " << std::endl;
	}
}
void insertSearch(int arr[], int insertNumber, int menu){
	int searchValue;
	int result;
	std::cout << "Enter a number from array: " << std::endl;
	std::cin >> searchValue;
	if(menu == 3){
		binarySearchValue(arr, insertNumber, searchValue, result);
	}
	if(menu == 4){
		sequentialSearchValue(arr, insertNumber, searchValue, result);
	}
}

int main() {
   int insertNumber;
   std::cout << "Enter the number of elements: ";
   std::cin >> insertNumber;
   int arr[insertNumber];
   for(int x = 0; x<insertNumber; x++) {
           std::cout << "Enter element " << x+1 <<": ";
        std::cin >> arr[x];
   }
	start:
	printOriginalArray(arr, insertNumber);
	std::cout << std::endl;
	int menu;
	std::cout << "Choose your program:" << std::endl;
	std::cout << "1. Merge Sort Ascending" << std::endl;
	std::cout << "2. Merge Sort Descending" << std::endl;
	std::cout << "3. Search index number using binary search" << std::endl;
	std::cout << "4. Search index number using sequential search" << std::endl;
	std::cout << "0. Quit" << std::endl;	
	std::cout << "______________________________________________" << std::endl;
	std::cin >> menu;
	std::cout << std::endl;
    switch(menu){
		case 0:{
			return 0;
			break;
		}
		
		case 1:{
			divideArray(arr, 0, insertNumber-1, menu);
			printModifiedArray(arr, insertNumber);
			break;
		}
		
		case 2:{
			divideArray(arr, 0, insertNumber-1, menu);
			printModifiedArray(arr, insertNumber);
			break;
		}
		
		case 3:{
			insertSearch(arr, insertNumber, menu);
			break;
		}
		
		case 4:{
			insertSearch(arr, insertNumber, menu);
			break;
		}
	}
	std::string looping;
	std::cout << std::endl;
	std::cout << "Do you want start again? y/n" << std::endl;
	std::cin >> looping;
	if(looping == "y" || looping == "Y"){
		std::string repeat;
		std::cout << "Do you want to insert new array? y/n" << std::endl;
		std::cin >> repeat;
		std::cout << std::endl;
		if(repeat == "y" || repeat == "Y"){
			return main();
		}else{
			goto start;
		}
	}else{
		return 0;
	}
}
