The purpose of this project is more of to simulate some routers/switches on a network.  This does not include any router programming; more of simulate how routers work visually and some of the routing protocols.

Initially, the program is going to be text based, but in the fitre, I'd like to graphically simuate the routers communicating.

Thoughts & Planning:

routers:
	name
	interfaces: one+
		name:
		speed: ??? may be needed for the dynamically route metrics
		ipv4 addr:	only one
		ipv4 netmask: - autogen
		ipv6 {	-- 1+ or optional
			ipv6 addr:
			ipv6 netmask: - autogen
		}
		routing protocal:
			static
			?? is-is
				-- uses Dijkstra's algorithm to determine the best path
			ripv1
				-- rip has a max hop count of 15, 0=directly connected, 16=unroutable
					rip counts the number of router it goes through for hop counts
				-- is classful only, so does not carry subnet info
				--sends full routing table , adding other routing tables to it's own
			ripv2 -- RIPng = ipv6 only, regular ripv1&2 are ipv4
				-- supports cidr notation
				-- rip has a max hop count of 15, 0=directly connected, 16=unroutable
					rip counts the number of router it goes through for hop counts
			eigrp -- going to ignore IGRP, as EIGRP is the expansion off it
				--uses a metric of of the function of (Bandwidth+Delay)*256
					--bandwidth = 10^7 kbs/connection speed
						--(10Gbs)
			ospf
				-- uses Dijkstra's algorithm to determine the best path
				-- does not share routing tables
				-- forms a adjacency table of neighbor tables
				-- each area forms it's own link-state table
				-- uses a metric of 10^8/bandwidth (100Mbs = 1)
				-- I don't know how much I want to get into the various areas, and the DR/BDR
			?? bgp
			?? egp

		IS-IS and OSPF uses Dijkstra's algorithm

*** each interface will a hardcoded responce to loopback
*** set up each type of routing protocol, probably starting with static and rip1
*** future: add in switches and end computers
**** allow pinging between all end points
