https://leetcode.com/problems/robot-bounded-in-circle/

import java.util.*;
public class RobotBoundedInCircle {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		String s = scn.nextLine();
		
		String direction = "North";
		int x = 0;
		int y = 0;
		for(int i = 0; i < s.length(); i++) {
			char ch = s.charAt(i);
			if(ch == 'G') {
				if(direction.equals("North")) {
					y++;
				}
				else if(direction.equals("South")) {
					y--;
				}
				else if(direction.equals("West")) {
					x--;
				}
				else {
					x++;
				}
			}
			else if(ch == 'L') {
				if(direction.equals("North")) {
					direction = "West";
				}
				else if(direction.equals("South")) {
					direction = "East";
				}
				else if(direction.equals("West")) {
					direction = "South";
				}
				else {
					direction = "North";
				}
			}
			else {
				if(direction.equals("North")) {
					direction = "East";
				}
				else if(direction.equals("South")) {
					direction = "West";
				}
				else if(direction.equals("West")) {
					direction = "North";
				}
				else {
					direction = "South";
				}
			}
			
		}
		if(x == 0 && y == 0) {
			System.out.println(true);
		}else if(direction.equals("North")) {
			System.out.println(false);
		}
		System.out.println(true);
	}
  
  //just use return keyWord at every place i used System.out.println()
