
#include "synology.nas.file.stacker.hpp"
#include <flame/log.hpp>
#include <flame/config_def.hpp>

using namespace flame;

static synology_nas_file_stacker* _instance = nullptr;
flame::component::object* create(){ if(!_instance) _instance = new synology_nas_file_stacker(); return _instance; }
void release(){ if(_instance){ delete _instance; _instance = nullptr; }}

bool synology_nas_file_stacker::on_init(){
    console::info("<{}> call synology_nas_file_stacker on_init", _THIS_COMPONENT_);

    //connect
    return true;
}

void synology_nas_file_stacker::on_loop(){
    console::info("<{}> call synology_nas_file_stacker on_loop", _THIS_COMPONENT_);

    static int n = 0;
    std::string message = fmt::format("push {}",n);
    zmq::message_t zmq_message(message.data(), message.size());
    this->get_dataport()->send(zmq_message, zmq::send_flags::dontwait);

    console::info("{} : {}", _THIS_COMPONENT_, message);

    n++;
}

void synology_nas_file_stacker::on_close(){
    console::info("<{}> call synology_nas_file_stacker on_close", _THIS_COMPONENT_);
}

void synology_nas_file_stacker::on_message(){
    console::info("<{}> call synology_nas_file_stacker on_message", _THIS_COMPONENT_);
}