#include <iostream>
#include <vector>

//UTF-8s

class Client
{
private:
	std::string _name;
	int _id;
	//static std::vector<Client*>_clients;
	void ShowClient()
	{
		std::cout << "Имя: " << _name << '\n';
		std::cout << "Id: " << _id << '\n';
	}
public:
	Client(std::string name, int id, std::vector<Client*>& client) : _name(name), _id(id)
	{
		//_clients.push_back(this);
		client.push_back(this);
	}

	void ShowClients(std::vector<Client*>&clients)
	{
		for (const auto& it : clients)
			it->ShowClient();
	}
	/*static void ShowClients()
	{
		for (const auto& it : _clients)
			it->ShowClient();
	}*/
};

//std::vector<Client*>Client::_clients;

int main() {

	setlocale(LC_ALL, "Russian");
	std::vector<Client*> clients;
	Client* client = new Client("Саня", 20,clients);
	Client* client2 = new Client("Александр", 25, clients);
	Client* client3 = new Client("Главный хакер РЖД", 26, clients);
	/*client->ShowClient();
	client2->ShowClient();    
	client3->ShowClient();*/
	client->ShowClients(clients); //Вызов метода по обращении к объекту 
	//Client::ShowClients(); // Вызов метода по обращении к классу (если статик)



	return 0;
}