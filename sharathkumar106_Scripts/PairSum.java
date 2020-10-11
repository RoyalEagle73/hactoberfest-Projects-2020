import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Example_1_PairSum {

	// Naive Method
	public static void findPair_Naive(int[] arr, int sum) {
		
		// Iterate through the array except last element
		for(int i = 0; i < arr.length - 1; i++) {
			
			// Iterate from 'i'th element till the last element
			for(int j = i + 1; j < arr.length; j++) {
				
				// Pair found with given sum
				if(arr[i] + arr[j] == sum) {
					System.out.println("Pair found at index " + i + " and " + j);
					return;
				}
			}
		}
		
		// No pair exists with given sum
		System.out.println("Pair not found");
	}
	
	
	// Sorting Method
	public static void findPair_Sort(int[] arr, int sum) {
		
		// Sort the array in ascending order
		Arrays.sort(arr);
		
		// Set up 2 indices pointing to end-points of the array
		int low = 0;
		int high = arr.length - 1;
		
		// Reduce search space arr[low...high] at each iteration of the loop till low < high
		while(low < high) {
			
			// Pair found with given sum
			if(arr[low] + arr[high] == sum) {
				System.out.println("Pair found at index " + low + " and " + high);
				return;
			}
			
			// Increment low index if sum is lower than the desired
			// Decrement high index if sum is greater than the desired
			if(arr[low] + arr[high] < sum) {
				low++;
			}
			else {
				high--;
			}
		}
		// No pair exists with given sum
		System.out.println("Pair not found");
	}
	
	// Hashing Method
	public static void findPair_Hash(int[] arr, int sum) {
		
		// Create an empty map
		Map<Integer,Integer> map = new HashMap<>();
		
		// Iterate through the array and check if the difference (sum - arr[i]) exists in the map
		for( int i = 0; i < arr.length; i++) {
			if(map.containsKey(sum - arr[i])){
				System.out.println("Pair found at index " + map.get(sum - arr[i]) + " and " + i);
				return;
			}
			
			// Store index of current element in map
			map.put(arr[i], i);
		}
		
		// Pair not found
		System.out.println("Pair not found");
	
	}
	
	public static void main(String[] args) {
		 
		int[] arr = { 8, 7, 2, 5, 3, 1 };
	    int sum = 10;
	    
	    // Naive approach
	    findPair_Naive(arr, sum);
	    
	    // Sorting approach
	    findPair_Sort(arr, sum);
	    
	    // Hashing approach
	    findPair_Hash(arr, sum);

	}

}
