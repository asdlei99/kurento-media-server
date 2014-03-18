/* Autogenerated with Kurento Idl */

#ifndef __MEDIA_ELEMENT_HPP__
#define __MEDIA_ELEMENT_HPP__

#include <jsoncpp/json/json.h>
#include <JsonRpcException.hpp>
#include <ObjectRegistrar.hpp>
#include <memory>
#include <vector>
#include "MediaObject.hpp"

namespace kurento {

class MediaSource;
class MediaType;
class MediaSink;
class MediaElement;

class MediaElement : public virtual MediaObject {

public:

  MediaElement () {};
  virtual ~MediaElement () {};

  virtual std::vector<std::shared_ptr<MediaSource>> getMediaSrcs () {throw "Not implemented";};
  virtual std::vector<std::shared_ptr<MediaSource>> getMediaSrcs (std::shared_ptr<MediaType> mediaType, const std::string& description) {throw "Not implemented";};
  virtual std::vector<std::shared_ptr<MediaSource>> getMediaSrcs (std::shared_ptr<MediaType> mediaType) {throw "Not implemented";};
  virtual std::vector<std::shared_ptr<MediaSink>> getMediaSinks () {throw "Not implemented";};
  virtual std::vector<std::shared_ptr<MediaSink>> getMediaSinks (std::shared_ptr<MediaType> mediaType) {throw "Not implemented";};
  virtual std::vector<std::shared_ptr<MediaSink>> getMediaSinks (std::shared_ptr<MediaType> mediaType, const std::string& description) {throw "Not implemented";};
  virtual void connect (std::shared_ptr<MediaElement> sink, std::shared_ptr<MediaType> mediaType, const std::string& mediaDescription) {throw "Not implemented";};
  virtual void connect (std::shared_ptr<MediaElement> sink, std::shared_ptr<MediaType> mediaType) {throw "Not implemented";};
  virtual void connect (std::shared_ptr<MediaElement> sink) {throw "Not implemented";};

  virtual std::string connect(const std::string &eventType, std::shared_ptr<EventHandler> handler);

  class Factory : public virtual kurento::Factory
  {
  public:
    Factory () {};

    virtual std::string getName () {
      return "MediaElement";
    };

  private:

    virtual MediaObject * createObjectPointer (const Json::Value &params);

    MediaObject * createObject (int garbagePeriod);

    class StaticConstructor
    {
    public:
      StaticConstructor();
    };

    static StaticConstructor staticConstructor;

  };

  class Invoker : public virtual MediaObject::Invoker
  {
  public:
    Invoker() {};
    virtual void invoke (std::shared_ptr<MediaObject> obj,
        const std::string &methodName, const Json::Value &params,
        Json::Value &response);
  };

  virtual MediaObject::Invoker &getInvoker() {
    return invoker;
  }

  private:
    Invoker invoker;

};

} /* kurento */

#endif /*  __MEDIA_ELEMENT_HPP__ */
