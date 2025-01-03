#include "app.h"

int main() {
    SimpleShapeApplication app(1024, 720, PROJECT_NAME, true);
    app.run(1);

    return 0;
}