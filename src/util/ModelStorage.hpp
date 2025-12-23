//
// Created by eal on 19/12-2025.
//

#ifndef MODELSTORAGE_HPP
#define MODELSTORAGE_HPP
#include <memory>

#include "models/Club.hpp"
#include "models/League.hpp"
#include "models/Player.hpp"


class ModelStorage
{
public:
  explicit ModelStorage(const std::shared_ptr<spdlog::logger>& logger);
  void addClub(const std::shared_ptr<Club>& club);
  void addPlayer(const std::shared_ptr<Player>& player);
  void addLeague(const std::shared_ptr<League>& league);
  void addTransferOffer(const std::shared_ptr<TransferOffer>& offer);

  std::shared_ptr<Club> getClub(const std::string& uuid);
  std::shared_ptr<Player> getPlayer(const std::string& uuid);
  std::shared_ptr<League> getLeague(const std::string& uuid);
  std::shared_ptr<TransferOffer> getTransferOffer(const std::string& uuid);

  [[nodiscard]] std::vector<std::shared_ptr<TransferOffer>> getTransferOffers() const;

private:
  static std::string generateUuid();

  std::shared_ptr<spdlog::logger> logger_;

  std::unordered_map<std::string, std::shared_ptr<Club>> clubs_;
  std::unordered_map<std::string, std::shared_ptr<Player>> players_;
  std::unordered_map<std::string, std::shared_ptr<League>> leagues_;
  std::unordered_map<std::string, std::shared_ptr<TransferOffer>> transferOffers_;
};


#endif //MODELSTORAGE_HPP
