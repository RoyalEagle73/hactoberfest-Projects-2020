import java.util.Arrays;

public class Example_2_BinarySort {
	
	// Naive Approach
	public static void binarySort_Naive(int[] arr) {
		
		// Iterate through the array and count the number of 0's
		int zeroes = 0;
		for(int value : arr) {
			if(value == 0) {
				zeroes++;
			}
		}
		
		// Put 0's in the beginning
		int k = 0;
		while(zeroes-- > 0) {
			arr[k++] = 0;
		}
		
		// Fill all remaining elements by 1
		while(k < arr.length) {
			arr[k++] = 1;
		}
		System.out.println(Arrays.toString(arr));
	}

	// Comparison Approach
	public static void binarySort_Compare(int[] arr) {
		
		// Store the index of next available free index
		int k = 0;
		
		// Compare every element to 0 and if it matches, fill the next available index with a 0.
		for (int value : arr) {
			if (value == 0) {
				arr[k++] = 0;
			}
		}
		
		// Fill the rest of the array with 1's
		for (int i = k; i < arr.length; i++) {
			arr[i] = 1;
		}
		
		System.out.println(Arrays.toString(arr));
	}
	
	// Quick-sort Approach
	public static void binarySort_Quick(int[] arr) {
		// Set pivot to 1
		int pivot = 1;
		int j = 0;
		
		// Each time a 0 is encountered, we increment j
		// 0 is placed before the pivot
		for (int i = 0; i < arr.length; i++) {
			if (arr[i] < pivot) {
				swap(arr,i,j);
				j++;
			}
		}
		
		System.out.println(Arrays.toString(arr));
	}
	// Utility function to swap 2 elements in an array
	private static void swap(int[] arr, int i, int j) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	
	public static void main(String[] args) {
		
		int[] arr = {1, 0, 1, 0, 1, 0, 1, 1, 0, 0};
		
		// Naive Approach
		binarySort_Naive(arr);		
		
		// Comparison Approach
		binarySort_Compare(arr);
		
		// Quick-sort Approach
		binarySort_Quick(arr);
	}

}
