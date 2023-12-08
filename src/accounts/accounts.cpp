// Copyright 2023 <fleurs>

#include "accounts.hpp"

#include <unordered_map>
#include <set>
#include <string>
#include <utility>

 // TODO : on deposit check if >0;
 // TODO : on withdrawal check if money available >= withdrawing money;

 // id начинается с 0, но 0 id - служебный для ПУСТЫХ аккаунтов.

 namespace bank{
 class user_db{
   user_db(){
     // open connection
     // total_active_accounts_ = size(all_users); // каким-то образом
     // init all_users;
     // init prev_id = id of last user of db;
   }

   ~user_db(){
     // close connection
     // show that user_db is closed
   }
   class user{
    public:
     user(){
       id_ = user_db::prev_id_ + 1;
       user_db::prev_id_ = id_;
       money_ = 0;
     }

     user(unsigned int money, std::string& name) : money_(money), name_(std::move(name)){
       id_ = user_db::prev_id_ + 1;
       user_db::prev_id_ = id_;
       ++user_db::total_active_accounts_;
     }

     user(user &other) = delete;

     user(user &&other) = delete;

     ~user(){
       id_ = 0;
       money_ = 0;
       --user_db::total_active_accounts_;
     }

    private:
     unsigned int id_;
     unsigned int money_;
     std::string name_;
   };

   static unsigned int total_active_accounts_;
   static std::unordered_map<unsigned int, user> all_users; // key: id, pred: user
   static unsigned int prev_id_;
 };
}
