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
			ripv1
			ripv2
			eigrp
			ospf
			?? bgp
			?? any others
		
*** each interface will a hardcoded responce to loopback
*** set up each type of routing protocol, probably starting with static and rip1
*** future: add in switches and end computers
**** allow pinging between all end points