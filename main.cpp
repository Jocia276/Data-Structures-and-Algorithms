#include "teste.h"
#include "UserInterface.h"
#include "Friendship.h"

int main() {

    teste();
    Repo<User> repo;
    Repo<Friendship> repoF;
    Repo<Messages> repoM;
    RepoEvent<Event> repoE;
    Service srv(repo, repoF, repoM, repoE);
    UserInterface ui(srv);
    ui.runApp();

    return 0;
}