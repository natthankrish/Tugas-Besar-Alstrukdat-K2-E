#include <stdio.h>

void printHelp() {
    puts(
    "                                ----------------------------------------------------------------------\n"
    "                                                         BNMO ASISTANCE CENTER\n"
    "                                ----------------------------------------------------------------------\n\n"
    "Initialize and Terminate\n"
    "-----------------------------------------------------------------------------------------------------------------------------------\n"
    "     START                         Start the application and read the configuration\n"
    "     EXIT                          Exit the application\n"
    "     HELP                          Help to see the explanation of the appliation especially the command\n\n"
    "Map Explained\n"
    "-----------------------------------------------------------------------------------------------------------------------------------\n"
    "     X                             Wall\n"
    "     F                             Frying site\n"
    "     C                             Cooking site\n"
    "     M                             Mixing site\n"
    "     B                             Boiling site\n"
    "     T                             Buying site\n\n"
    "Order food\n"
    "-----------------------------------------------------------------------------------------------------------------------------------\n"
    "     BUY                           Place an order\n"
    "     DELIVERY                      Display food orders\n\n"
    "BNMO navigation\n"
    "-----------------------------------------------------------------------------------------------------------------------------------\n"
    "     MOVE NORTH                    Move BNMO by one unit to North according to the cardinal directions\n"
    "     MOVE SOUTH                    Move BNMO by one unit to South according to the cardinal directions\n"
    "     MOVE EAST                     Move BNMO by one unit to East according to the cardinal directions\n"
    "     MOVE WEST                     Move BNMO by one unit to West according to the cardinal directions\n\n"
    "Food processing\n"
    "-----------------------------------------------------------------------------------------------------------------------------------\n"
    "     MIX                           Mixing two or more foods from inventory into one food \n"
    "     CHOP                          Chop one food ingredients from inventory into slices \n"
    "     FRY                           Fry one on more ingredients from inventory \n"
    "     BOIL                          Boil one on more ingredients from inventory\n\n"
    "Mechanism of time\n"
    "-----------------------------------------------------------------------------------------------------------------------------------\n"
    "     WAIT [<hours>] [<minutes>]    Fast-forward the time\n\n"
    "Others\n"
    "-----------------------------------------------------------------------------------------------------------------------------------\n"
    "     CATALOG   Display detailed information on ingredients and food available on the application\n"
    "     UNDO      Cancel the command executed by the simulator and returns the application state to before the command was executed\n"
    "     REDO      Cancel the undo command\n"
    );
}