
/*
 * Returns a tuple of (transport, kthxbyeFn) where kthxbye is used for flushing logs to cloudwatch
 * and exit. (Otherwise lambda function would be unable to exit.)
 */
let createCloudwatch: (
  ~logGroupName: string,
  ~logStreamName: string,
  ~level: string =?,
  ~awsAccessKeyId: string =?,
  ~awsSecretKey: string =?,
  ~awsRegion: string =?,
  ~awsOptions: Js.Dict.t(Js.Json.t) =?,
  ~jsonMessage: bool =?,
  ~messageFormatter: (Js.Dict.t(Js.Json.t) => Js.Dict.t(Js.Json.t)) =?,
  ~proxyServer: string =?,
  ~uploadRate: int =?,                     /* in ms. default 2000 */
  ~errorHandler: (Js.t('a) => unit) =?,
  ~retentionInDays: int =?,
  unit
) => (BsWinston.Transport.t, ((unit => unit) => unit));
