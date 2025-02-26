#include "core.cxx"
// #include "bot.cc"

// fn sp() {
//     CROW_ROUTE(server, "/json")
//     ([]{
//         crow::json::wvalue x({{"message", "Hello, World!"}});
//         x["message2"] = "Hello, World.. Again!";
//         return x;
//     });

//     server.port(80)
//     .server_name("Core")
//     .multithreaded().run();
// }

fn $init() {
    argopt.add_options()
            ("t,test", "Run in test mode")
            ("d,debug", "Enable debugging")
            ("server", "Enable server mode")
            ("dev", "Enable development mode");
}

static int TEST = 0, DEBUG = 0, DEV = 0, SERVER = 0;

fn $head(const int argc, char *argv[]) {
    const auto result = argopt.parse(argc, argv);

    if (result.count("test")) {
        TEST = 1;
        print("Running in test mode.");
    }

    if (result.count("debug")) {
        DEBUG = 1;
        print("Debugging enabled.");
    }

    if (result.count("dev")) {
        DEV = 1;
        print("Development enabled.");
    }

    if (result.count("server")) {
        SERVER = 1;
        print("Server enabled.");
    }
}

fn $run() {
    // fire.task([]() -> void {
    //     if (!TEST) return;
    //     constexpr static auto chat_id = "5941066026"; // Replace with your chat ID
    //     constexpr static auto message = "Choose an option:";
    //     constexpr static auto parse_mode = "Markdown"; // or "HTML"
    //     Json::Value keyboard = telegram.createKeyboard(panel_main);
    //     telegram.sendMessage(chat_id, message, parse_mode, keyboard);
    // });
    fire.task([]() -> void {
        if (!SERVER) return;
        // sp();
    });
    fire.task([]() -> void {
        try {
         // auto response = fetch.get("https://example.com");
            std::string str = exec("cd "s + getDirectory() + "; ls");
            echo("res: " << "'" << str << "'");

    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

});
}

fn $end() { /* Cleanup */ }
