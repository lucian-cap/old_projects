General Thoughts:
	The entire program will be easier if a Process object is detailed	
		This will need to hold the: id, priority, length, and wait time
	Will also use two static variables, one to hold valid IDs and another
		to hold the processes that have been made so far

Process class:
	Two constructors, no arg and one with an arg (this one is used to pass in an id)
	Once the process is created with random (mostly) attributes it's added to the allProcess static list
	getters for most of the data fields
	A wait method to increment the wait time for the process using an int passed in
	A getProcessInfo() method that prints out the info of all processes neatly
	
	SJF method:
		Use a temp array for convience, sorted based on length (min first)
		Use two loops, one to iterate through the entire list and the other to iterate from the current place + 1 from the outer loop to the end
		The second loop increments the wait time of each process by the length of the current process
		Simple logic to get the average wait time and prints out the info of the method
		
		
	Priority method:
		Same general logic as SJF method except list is sorted on priority
		
	
	roundRobin method:
		Sort the temp list on IDs
		save the length of each Process in a separate arrayList
		While loop, which runs as long as a process is in temp arrayList
			For loop, which runs the length of the temp list
				If/else conditions to set the change value based on which the current processes time is
					if it's more than the value entered then use that, otherwise use the current processes length
				for loop, iterating through entire temp list
					if index in inner loop matches that in the outer loop, decrement the length by the change
					else, increase the wait time by change
					
			For loop, through entire temp list
				if the length of the process is 0 (its finished) remove it
			
		Add all the Processes back to the temp list
		Sort on ID again
		Set the lengths back to their original values used the tempLen arrayList
		Same logic as above from here on out, get total wait time and print 
		
		
		
Main Function:
	Create scanner and temp arrayList
	for loop, making 5 random processes using the no arg constructor
	Use first object to print out info on all processes
	Create id arrayList, which has some values as the Process static identifiers list
	Get user input
	while loop, if the user input is in the id arrayList, get different input
	create new process using the users input
	reprint all process info
	Print newlines, then scheduling method info over again until the last call to round robin