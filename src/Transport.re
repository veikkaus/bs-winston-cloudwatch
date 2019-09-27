
module Cloudwatch {
  [@bs.deriving abstract]
  type config('a) = {
    logGroupName: string,
    logStreamName: string,
    [@bs.optional] level: string,
    [@bs.optional] awsAccessKeyId: string,
    [@bs.optional] awsSecretKey: string,
    [@bs.optional] awsRegion: string,
    [@bs.optional] awsOptions: Js.Dict.t(Js.Json.t),
    [@bs.optional] jsonMessage: bool,
    [@bs.optional] messageFormatter: (Js.Dict.t(Js.Json.t) => Js.Dict.t(Js.Json.t)),
    [@bs.optional] proxyServer: string,
    [@bs.optional] uploadRate: int,
    [@bs.optional] errorHandler: (Js.t('a) => unit),
    [@bs.optional] retentionInDays: int
  };
  [@bs.new] [@bs.module] external newWinstonCloudwatch: config('a) => BsWinston.Transport.t = "winston-cloudwatch";
  [@bs.send] external kthxbye: BsWinston.Transport.t => (unit => unit) => unit = "kthxbye";
  let create =
    (~logGroupName, ~logStreamName, ~level=?, ~awsAccessKeyId=?, ~awsSecretKey=?, ~awsRegion=?, ~awsOptions=?,
     ~jsonMessage=?, ~messageFormatter=?, ~proxyServer=?, ~uploadRate=?, ~errorHandler=?, ~retentionInDays=?, ())/*: (BsWinston.Transport.t, (unit => Js.Promise.t(unit)))*/ => {
      let transport = newWinstonCloudwatch(config(
        ~logGroupName = logGroupName,
        ~logStreamName = logStreamName,
        ~level =? level,
        ~awsAccessKeyId =? awsAccessKeyId,
        ~awsSecretKey =? awsSecretKey,
        ~awsRegion =? awsRegion,
        ~awsOptions =? awsOptions,
        ~jsonMessage =? jsonMessage,
        ~messageFormatter =? messageFormatter,
        ~proxyServer =? proxyServer,
        ~uploadRate =? uploadRate,
        ~errorHandler =? errorHandler,
        ~retentionInDays =? retentionInDays,
        ()
      ));
      let kthxbye =
        () => Js.Promise.make((~resolve, ~reject as _) => {
          let empty = ();
          kthxbye(transport, () => resolve(. empty));
        });
      (transport, kthxbye);
    };
}
let createCloudwatch = Cloudwatch.create;
