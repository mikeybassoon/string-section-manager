# string-section-manager
Tool for calculating string section rotations for a professional orchestra

Copyright (c) 2018-2019, Michael Macaulay

Permission is granted to all users to use and modify this code for personal or professional use.

Based on a previously existing existing season schedule, this program allocates musicians to new programs added to an orchestra season on the following basis:
	- Each new program is classified according to subscription series (Masterworks, Pops, Specials or Kids)
	- Priority is given to those musicians who have previously been scheduled for the least number of concert cycles on the subscription series in question
	- In case of a tie, priority will be given to the musician who has previously been scheduled for the least number of concert cycles across ALL subscription series
	- If there is still a tie, priority will be determined by random coin flip
