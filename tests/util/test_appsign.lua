return function(ok)
  local AppSign = require("core.util.appsign")
  local BuildSvc = require("frontend.love2d.buildsvc")

  local rs = AppSign.find_rabbitsign(".")
  ok("appsign find or skip", true) -- always pass; presence checked below

  local src = [[
void main() {
  os_clr_lcd();
  os_home_up();
  os_put_str("SIGN");
  os_exit();
}
]]

  local unsigned, uerr = BuildSvc.build_tc_app(".", src, {
    app_name = "SIGNTEST",
    entry = "sign.tc",
    sign = false,
  })
  ok("appsign unsigned build", unsigned ~= nil, tostring(uerr))
  if unsigned then
    ok("appsign unsigned TIFL", unsigned:sub(1, 8) == "**TIFL**")
  end

  if not rs then
    ok("appsign rabbitsign present", false,
      "run tools/install_rabbitsign.sh or tools/install_rabbitsign.ps1")
    return
  end

  ok("appsign rabbitsign present", true)

  local signed, serr, _, _, info = BuildSvc.build_tc_app(".", src, {
    app_name = "SIGNTEST",
    entry = "sign.tc",
    sign = true,
  })
  ok("appsign signed build", signed ~= nil, tostring(serr))
  if signed and unsigned then
    ok("appsign signed larger", #signed > #unsigned + 64)
    ok("appsign info.signed", info and info.signed == true)
    local again, aerr = AppSign.sign_bytes(unsigned, { root = "." })
    ok("appsign sign_bytes", again ~= nil, tostring(aerr))
    if again then
      ok("appsign deterministic size", #again == #signed)
    end
    -- Re-sign an already-signed app
    local resign, rerr = AppSign.sign_bytes(signed, { root = ".", resign = true })
    ok("appsign resign", resign ~= nil, tostring(rerr))
    if resign then
      ok("appsign resign size", #resign == #signed)
    end
  end
end
