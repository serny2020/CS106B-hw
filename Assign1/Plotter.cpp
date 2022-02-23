#include "Plotter.h"
#include "strlib.h"
#include "vector.h"

using namespace std;

void runPlotterScript(istream& input) {
    /* TODO: Delete this line and the one after it, then implement this function. */
//    (void) input;
    PenStyle style = {1, "black"};
    double x0 = 0;
    double y0 = 0;
    int pen_status = 0; // PenUp is 0

    for (string line; getline(input, line); ){
        Vector<string> commands = stringSplit(line, " ");
        if (startsWith(toLowerCase(commands[0]), "penup")){
            pen_status = 0;

        }else if (startsWith(toLowerCase(commands[0]), "pendown")){
            pen_status = 1; // PenDown is 1

        }else if (startsWith(toLowerCase(commands[0]), "moveabs")){
            double x = stringToReal(commands[1]);
            double y = stringToReal(commands[2]);
            if (pen_status){ // if pen is down, draw line
                drawLine(x0, y0, x, y, style);
            }
            x0 = x;
            y0 = y;

        }else if (startsWith(toLowerCase(commands[0]), "moverel")){
            double dx = stringToReal(commands[1]);
            double dy = stringToReal(commands[2]);
            double x = x0 + dx;
            double y = y0 + dy;
            if (pen_status){ // if pen is down, draw line
                drawLine(x0, y0, x, y, style);
            }
            x0 = x;
            y0 = y;

        }else if (startsWith(toLowerCase(commands[0]), "penwidth")){
            style.width = stringToReal(commands[1]);

        }else if (startsWith(toLowerCase(commands[0]), "pencolor")){
            style.color = commands[1];

        }

    }
}
