# Continuous Integration

## Part A

- Test java.util.PriorityQueue class with Junit (Hint: import java.util.PriorityQueue;)
- Parameterization
  - Each testcase : { random array } , { correct array }. (Hint: use int[])
			                random array : means to specify your own input array
  - Correct array means the PriorityQueue polling correct order instead of using toArray().
  - Your test must have at least 5 unique testcases.
- Exception
  - You have to test at least 3 unique Exceptions that is thrown by PriorityQueue.
  - The same name of Exception but different position is accepted.

## Part B

- Deploy your Part A (PriorityQueueTest.java) on Github with public
- The repository is your student id
- Connecting Travis CI with your Github
- Make sure that Travis CI can build and test automatically
- Add Travis CI’s build mark to your README.md file
- You must have two commit :
  - Pass all testcases
  - Fail, changing your testcase make Travis CI fail
- Add result(Pass and Fail) screenshot to your README.md file
- Upload the URL of your Github repo to E3
