#include "Context.h"
#include "Application.h"

int main() {
    Context* c = new Context();

    Application app(c);

    app.start();

    return 0;
}