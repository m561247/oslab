import java.util.concurrent.ForkJoinPool;
import java.util.concurrent.RecursiveTask;

public class ForkJoinSum implements sumOfArray {
	private ForkJoinPool pool;

	
	
	private static class SumTask extends RecursiveTask<Long> {
		private long[] numbers;
		private int from;
		private int to;
		
		public SumTask(long[] numbers, int from, int to) {
			this.from = from;
			this.numbers = numbers;
			this.to = to;
		} 
		@Override
		protected Long compute() {
			if (to - from < 6) {
				long total = 0;
				for (int i = from; i <= to; i++) {
					total += numbers[i];
				}
				return total;
			} else {
				int split = (from + to) / 2;
				SumTask f1 = new SumTask(numbers, from, split);
				SumTask f2 = new SumTask(numbers, split + 1, to);
				f1.fork();
				return f2.compute() + f1.join();
			}
			
		}
		
	}
	public ForkJoinSum() {
		pool = new ForkJoinPool();
	}
	
	public long sumUp(long[] numbers) {
		return pool.invoke(new SumTask(numbers, 0, numbers.length-1));
	}
}
