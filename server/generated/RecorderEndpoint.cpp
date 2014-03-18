/* Autogenerated with Kurento Idl */

#include <memory>

#include "MediaPipeline.hpp"
#include "MediaProfileSpecType.hpp"
#include "RecorderEndpoint.hpp"
#include <JsonSerializer.hpp>

namespace kurento {

MediaObject * RecorderEndpoint::Factory::createObjectPointer (const Json::Value &params)
{
  std::shared_ptr<MediaPipeline> mediaPipeline;
  std::string uri;
  std::shared_ptr<MediaProfileSpecType> mediaProfile;
  bool stopOnEndOfStream = false;
  int garbagePeriod = 0;

  if (!params.isMember ("mediaPipeline")) {
    /* param 'mediaPipeline' not present, raise exception */
    JsonRpc::CallException e (JsonRpc::ErrorCode::SERVER_ERROR_INIT,
                              "'mediaPipeline' parameter is requiered");
    throw e;
  } else {
    JsonSerializer s(false);
    s.JsonValue = params;
    s.SerializeNVP(mediaPipeline);
  }

  if (!params.isMember ("uri")) {
    /* param 'uri' not present, raise exception */
    JsonRpc::CallException e (JsonRpc::ErrorCode::SERVER_ERROR_INIT,
                              "'uri' parameter is requiered");
    throw e;
  } else {
    JsonSerializer s(false);
    s.JsonValue = params;
    s.SerializeNVP(uri);
  }

  if (!params.isMember ("mediaProfile")) {
    /* param 'mediaProfile' not present, using default */
    mediaProfile = std::shared_ptr<MediaProfileSpecType> (new MediaProfileSpecType ("WEBM"));
  } else {
    JsonSerializer s(false);
    s.JsonValue = params;
    s.SerializeNVP(mediaProfile);
  }

  if (!params.isMember ("stopOnEndOfStream")) {
    /* param 'stopOnEndOfStream' not present, using default */
    stopOnEndOfStream = false;
  } else {
    JsonSerializer s(false);
    s.JsonValue = params;
    s.SerializeNVP(stopOnEndOfStream);
  }

  if (!params.isMember ("garbagePeriod")) {
    /* param 'garbagePeriod' not present, using default */
    garbagePeriod = 120;
  } else {
    JsonSerializer s(false);
    s.JsonValue = params;
    s.SerializeNVP(garbagePeriod);
  }

  return createObject (mediaPipeline, uri, mediaProfile, stopOnEndOfStream, garbagePeriod);
}

RecorderEndpoint::Factory::StaticConstructor RecorderEndpoint::Factory::staticConstructor;

RecorderEndpoint::Factory::StaticConstructor::StaticConstructor()
{
  if (objectRegistrar) {
    std::shared_ptr <Factory> factory (new RecorderEndpoint::Factory());

    objectRegistrar->registerFactory(factory);
  }
}

void
RecorderEndpoint::Invoker::invoke (std::shared_ptr<MediaObject> obj,
    const std::string &methodName, const Json::Value &params,
    Json::Value &response)
{
  if (methodName == "record" && params.size() == 0) {
    Json::Value aux;

    // TODO: Implement method record
    std::shared_ptr<RecorderEndpoint> finalObj;
    finalObj = std::dynamic_pointer_cast<RecorderEndpoint> (obj);
    if (!finalObj) {
      JsonRpc::CallException e (JsonRpc::ErrorCode::SERVER_ERROR_INIT,
                                "Object not found or has incorrect type");
      throw e;
    }

    finalObj->record ();
    return;
  }

  UriEndpoint::Invoker::invoke(obj, methodName, params, response);
}

std::string
RecorderEndpoint::connect(const std::string &eventType, std::shared_ptr<EventHandler> handler)
{
  return UriEndpoint::connect (eventType, handler);
}

} /* kurento */

void
Serialize(std::shared_ptr<kurento::RecorderEndpoint> &object, JsonSerializer &serializer)
{
  if (!serializer.IsWriter) {
    try {
      std::shared_ptr<kurento::MediaObject> aux;
      aux = kurento::RecorderEndpoint::Factory::getObject (serializer.JsonValue.asString ());
      object = std::dynamic_pointer_cast<kurento::RecorderEndpoint> (aux);
      return;
    } catch (kurento::JsonRpc::CallException &ex) {
      kurento::JsonRpc::CallException e (kurento::JsonRpc::ErrorCode::SERVER_ERROR_INIT,
                              "'RecorderEndpoint' object not found: "+ ex.getMessage());
      throw e;
    }
  }
  std::shared_ptr<kurento::UriEndpoint> aux = std::dynamic_pointer_cast<kurento::UriEndpoint> (object);

  void Serialize(std::shared_ptr<kurento::UriEndpoint> &object, JsonSerializer &serializer);
  Serialize(aux, serializer);
}

void
Serialize(kurento::RecorderEndpoint &object, JsonSerializer &serializer)
{
  void Serialize(kurento::UriEndpoint &object, JsonSerializer &serializer);
  try {
    Serialize(dynamic_cast<kurento::UriEndpoint &> (object), serializer);
  } catch (std::bad_cast) {
  }
}
