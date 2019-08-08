# string-section-manager
Tool for calculating string section rotations for a professional orchestra

Copyright (c) 2018-2019, Michael Macaulay

Permission is granted to all users to use and modify this code for personal or professional use. This program is not affiliated with or endorsed by the Regina Symphony Orchestra.

This program is based on the section rotation system in use at the Regina Symphony Orchestra and does not currently support other rotation systems. Based on the existing season schedule, this program allocates musicians to new programs added to the season on the following basis:
	- Each new program is classified according to subscription series (Masterworks, Pops, Specials or Kids)
	- Priority is given to those musicians who have previously been scheduled for the least number of concert cycles on the subscription series in question
	- In case of a tie, priority will be given to the musician who has previously been scheduled for the least number of concert cycles across ALL subscription series
	- If there is still a tie, priority will be determined by random coin flip
