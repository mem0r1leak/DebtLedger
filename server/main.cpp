#include "crow.h"

int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([] {
        return "Hello world";
    });
    CROW_ROUTE(app, "/json")([] {
        crow::json::wvalue user;
        return user;
    });

    app.port(3000).multithreaded().run();
}
