# Another Unit Testing

- Test ***java.util.PriorityQueue*** class with Junit
	- *import java.util.PriorityQueue;*
- Parameterization
  - Each testcase : { ***random array*** } , { ***correct array*** }.
  	- ***Random array*** means to specify your own input array.
  	- ***Correct array*** means the PriorityQueue polling correct order instead of using toArray().
  	- e.g. *arguments(new int[]{5, 4, 2, 3}, new int[]{2, 3, 4, 5});*
  - Your test must have at least **5** unique testcases.
- Exception
  - You have to test at least **3** unique Exceptions that is thrown by PriorityQueue.
  - The same exception in different ways is accepted.
