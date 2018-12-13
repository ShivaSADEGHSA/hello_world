//
//  Electric_Vehicle_Routing_Problem.hpp
//  
//
//  Created by Shohre Sadeghsa on 13/12/2018.
//

#ifndef Electric_Vehicle_Routing_Problem_hpp
#define Electric_Vehicle_Routing_Problem_hpp

#include "Electric_Vehicle_Routing_Problem.hpp"
#include <iostream>
#include <string>
#include<list>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <tinyxml.h>
#include<cmath>
#include <algorithm>
using namespace std;

//**********************************************DATA DEFINTION******************************
typedef struct Edge{
    
    int i,j;
    double distance_ij;
    double time_ij;
    double consumtion_ij;
    
}Edge;

typedef list<Edge>ListEdge;
typedef ListEdge::iterator ItEdge; //listes of edges
// ***********************************

typedef struct BreakPoint{
    
    int id_breakpoint;
    int battery_level;
    double charging_time;
    double time_service_breakpoint;
    
}BreakPoint;


typedef vector<BreakPoint>ListBreakPoint;
typedef ListBreakPoint::iterator ItBreakPoint;

//******************************************************
typedef struct Station{
    
    int id_station;
    double x,y;
    char type_technology; // fast, slow or miderate
    // ListBreakPoint List_breakpoints_station;
    double time_service_station;
    double battery_level_arriving_station;
    double battery_level_leaving_station;
    double time_arrive_station;
    double time_leave_station;
    
}Station;

typedef vector<Station>ListStation;
typedef ListStation::iterator ItStation;

//******************************************************
typedef struct Node{
    
    int id_node;
    char *type=NULL;  // 0 depot  1 client   2 station
    double x,y;
    double time_service_node;
    double arriving_time_node;
    double leaving_time_node;
    double rest_time_node;     // =Tmax-leaving time
    double distance_to_depot;
    double distance_to_station;
    double consumtion_node_depot;
    double consumtion_node_station;
    double time_node_to_depot;
    double time_node_to_station;
    int id_near_station;
    
    Edge edge_enter;
    Edge edge_leave;
    
    
    double battery_capacity_arrive_node;
    double battery_capacity_leave_node;
    double rest_battery_capacity_node;
    
    int id_next_node;
    int id_last_node;
    
    Station station_node;
}Node;

typedef vector<Node>ListNode;
typedef ListNode::iterator ItNode;
//***************************************************
typedef struct Client{
    int id_client;
    double x,y;
    double time_service_client;
    double arriving_time_client;
    double leaving_time_client;
    double rest_time_client;     // =Tmax-leaving time
    double distance_client_to_depot;
    double distance_client_to_station;
    double consumtion_client_to_depot;
    double consumtion_client_station;
    double time_client_to_depot;
    double time_client_to_station;
    int id_near_station;
    
    Edge edge_enter;
    Edge edge_leave;
    
    
    double battery_capacity_arrive_node;
    double battery_capacity_leave_node;
    double rest_battery_capacity_node;
    
    int id_next_node;
    int id_last_node;
    
}Client;

typedef vector<Node>ListClient;
typedef ListNode::iterator ItClient;
//***************************************************
typedef struct Tour{
    
    int id_subtour;
    double time_subtour;
    double  center_cordination_X_subtour;  //for neighbor operator
    double  center_cordination_Y_subtour; //for neighbor operator
    double battery_capacity_subtour;
    
    ListNode list_visited_nodes;
    bool feasibility;
    bool feasibility_time_subtour;
    bool feasibility_battery_subtour;
}Tour;

typedef vector<Tour>ListTour;

typedef ListTour::iterator ItTour;

typedef struct Solution{
    
    int Id_solution;
    double distance_solution;
    double time_solution;
    ListTour TourstRealise;
    
    bool feasibility;
    double propapility;
    ListNode list_client_not_visited;
}Solution;

typedef vector<Solution>ListSolution;   // la liste de solution est aussi une population.
typedef ListSolution::iterator ItSolution;//
//*****************************************GLOBAL INPUTS****************************

char xml_file_name[95];
char txt_file_name[95];
char excel_file_name[95];
double epsilon=10E-14;
//**************************************GLOBAL DEFINTION****************************
Node node_depot;
int number_of_customers;
int number_of_stations;
int consumption_rate;
int battery_capacity;
double max_travel_time;

#endif /* Electric_Vehicle_Routing_Problem_hpp */
