import java.util.concurrent.ForkJoinPool;
import java.util.concurrent.RecursiveAction;

public class SortExample {

    public static void main(String[] args) {
        int[] array = new int[100];
        for (int i = 0; i < array.length; i++) {
            array[i] = (int) (Math.random() * 100);
        }
		System.out.print("Before : ");
        printArray(array);
        ForkJoinPool.commonPool().invoke(new MergeSortThread(array));
        System.out.print("After : ");
	    printArray(array);
    } 

    private static void printArray(int[] array) {

        for (int element : array) {
            System.out.print(element + " ");
        }
        System.out.println();
    }
}

class MergeSortThread extends RecursiveAction {
    private int[] array;
    private int arrayLength;

    public MergeSortThread(int[] array) {
        this.array = array;
        this.arrayLength = array.length;
    }

    @Override
    protected void compute() {
        if (arrayLength < 2) { 
        	System.out.println("Thread id = " + Thread.currentThread().getId() + " number = " + array[0]);
        	return;
		}
        int[] leftSubArray = new int[arrayLength / 2];
        int[] rightSubArray = new int[arrayLength - arrayLength / 2];

        System.arraycopy(array, 0, leftSubArray, 0, leftSubArray.length);
        System.arraycopy(array, leftSubArray.length, rightSubArray, 0, rightSubArray.length);

        var leftTask = new MergeSortThread(leftSubArray);
        var rightTask = new MergeSortThread(rightSubArray);

        leftTask.fork();
        rightTask.compute();
        leftTask.join();
        mergeSortedSubArr(leftSubArray, rightSubArray, array); 
    }
	public static void mergeSortedSubArr(int[] leftSubArray, int[] rightSubArray, int[] result) {
        int L = 0, R = 0, res = 0;
        while (L < leftSubArray.length && R < rightSubArray.length) {
            if (leftSubArray[L] <= rightSubArray[R]) {
                result[res++] = leftSubArray[L++];
            } else {
                result[res++] = rightSubArray[R++];
            }
        }
        while (L < leftSubArray.length) {
            result[res++] = leftSubArray[L++];
        }
        while (R < rightSubArray.length) {
            result[res++] = rightSubArray[R++];
        }
    }
}
